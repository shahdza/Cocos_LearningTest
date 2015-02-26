#include "CSVParser.h"


namespace CSVParser {

    Csv::Csv(const string& filename)
    {
        Parse(filename);
    }

    Csv::~Csv()
    {

    }


    void Csv::Load(const string& filename, string& Data)
    {
        // 读取文件数据
        FILE* pFile = fopen(filename.c_str(), "rb");
        if (!pFile) {
            return;
        }
        
        fseek(pFile, 0, SEEK_END);
        long len = ftell(pFile);
        
        char* pBuffer = new char[len + 1];
        
        fseek(pFile, 0, SEEK_SET);
        fread(pBuffer, 1, len, pFile);
        fclose(pFile);
        
        pBuffer[len] = 0;
        Data.assign(pBuffer, len);
        
        delete[] pBuffer;
    }


    void Csv::Parse(const string& filename)
    {
        // 清除之前的数据
        m_content.clear();
        m_strErrorInfo.clear();
        
        string text;
        Load(filename, text);
        
        if (text.size() == 0) {
            return;
        }
        
        // 定义状态
        enum StateType {
            NewFieldStart,      // 新字段开始
            NonQuotesField,     // 非引号字段
            QuotesField,        // 引号字段
            FieldSeparator,     // 字段分隔
            QuoteInQuotesField, // 引号字段中的引号
            RowSeparator,       // 行分隔符字符1，回车
            Error,              // 语法错误
        };
        
        Row Fields = Row();
        string strField;
        
        // 设置初始状态
        StateType State = NewFieldStart;
        
        for (int i = 0, size = text.size(); i < size; ++i) {
            const char& ch = text[i];
            
            switch (State) {
                case NewFieldStart: { // 新字段开始
                    if (ch == '"') {
                        State = QuotesField;
                    }
                    else if (ch == ',') {
                        Fields.push_back("");
                        State = FieldSeparator;
                    }
                    else if (ch == '\r' || ch == '\n') {
                        m_strErrorInfo = "语法错误：有空行";
                        State = Error;
                    }
                    else {
                        strField.push_back(ch);
                        State = NonQuotesField;
                    }
                }
                break;
                    
                case NonQuotesField: { // 非引号字段
                    if (ch == ',') {
                        Fields.push_back(strField);
                        strField.clear();
                        State = FieldSeparator;
                    }
                    else if (ch == '\r') {
                        Fields.push_back(strField);
                        State = RowSeparator;
                    }
                    else {
                        strField.push_back(ch);
                    }
                }
                break;
                    
                case QuotesField: { // 引号字段
                    if (ch == '"') {
                        State = QuoteInQuotesField;
                    }
                    else {
                        strField.push_back(ch);
                    }
                }
                break;
                    
                case FieldSeparator: { // 字段分隔
                    if (ch == ',') {
                        Fields.push_back("");
                    }
                    else if (ch == '"') {
                        strField.clear();
                        State = QuotesField;
                    }
                    else if (ch == '\r') {
                        Fields.push_back("");
                        State = RowSeparator;
                    }
                    else {
                        strField.push_back(ch);
                        State = NonQuotesField;
                    }
                }
                break;
                    
                case QuoteInQuotesField: { // 引号字段中的引号
                    if (ch == ',') {
                        // 引号字段闭合
                        Fields.push_back(strField);
                        strField.clear();
                        State = FieldSeparator;
                    }
                    else if (ch == '\r') {
                        // 引号字段闭合
                        Fields.push_back(strField);
                        State = RowSeparator;
                    }
                    else if (ch == '"') {
                        // 转义
                        strField.push_back(ch);
                        State = QuotesField;
                    }
                    else {
                        m_strErrorInfo = "语法错误： 转义字符 \" 不能完成转义 或 引号字段结尾引号没有紧贴字段分隔符";
                        State = Error;
                    }
                }
                break;
                    
                case RowSeparator: { // 行分隔符字符1，回车
                    if (ch == '\n') {
                        m_content.push_back(Fields);
                        Fields = Row(); // Fields.clear();
                        strField.clear();
                        State = NewFieldStart;
                    }
                    else {
                        m_strErrorInfo = "语法错误： 行分隔用了回车 \\r。但未使用回车换行 \\r\\n ";
                        State = Error;
                    }
                }
                break;
                    
                case Error: { // 语法错误
                    return;
                }
                break;

                default: break;
            }
        }
        // end for
        
        switch (State) {
            case NewFieldStart: {
                // Excel导出的CSV每行都以/r/n结尾。包括最后一行
            }
            break;
            
            case NonQuotesField: {
                Fields.push_back(strField);
                m_content.push_back(Fields);
            }
            break;
                
            case QuotesField: {
                m_strErrorInfo = "语法错误： 引号字段未闭合";
            }
            break;
                
            case FieldSeparator: {
                Fields.push_back("");
                m_content.push_back(Fields);
            }
            break;
                
            case QuoteInQuotesField: {
                Fields.push_back(strField);
                m_content.push_back(Fields);
            }
            break;
                
            case RowSeparator: {
                
            }
            break;
                
            case Error: {
                
            }
            break;
                
            default: break;
        }
        
        setHeader();
    }


    void Csv::setHeader()
    {
        m_header.clear();
        for (int i = 0; i < m_content[0].size(); i++) {
            m_header.push_back(m_content[0][i]);
        }
        for (int i = 0; i < m_content.size(); i++) {
            m_content[i].setHeader(&m_header);
        }
    }


    Row& Csv::operator[](unsigned int key)
    {
        if (key < m_content.size()) return m_content[key];
        throw "can't return this row (doesn't exist)";
    }

}
