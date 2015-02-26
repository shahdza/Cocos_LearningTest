#include <stdio.h>
#include <iostream>
using namespace std;

//[1] 引入头文件、命名空间
#include "CSVParser.h"
using namespace CSVParser;


int main()
{
//[2] csv文件完整路径
    string path = "/soft/cocos2d-x-3.4/projects/Demo34/Resources/testCSV.csv";

//[3] 解析csv文件
    Csv csv = Csv(path.c_str());

//[4] 获取总行数（包含列头）、总列数
    printf("总共有 %d 行\n", csv.getRowCount());
    printf("总共有 %d 列\n", csv.getColumnCount());
    
//[5] 获取所有数据（第0行为列头字段）
    // csv.getRowCount() : 数据总行数（包含列头）
    for (int i =0; i < csv.getRowCount(); i++) {
        // csv[i].size() : 每条数据有多少字段
        for (int j = 0; j < csv[i].size(); j++) {
            printf("%s,", csv[i][j].c_str());
        }
        puts("");
    }
    
//[6] 也可以根据列头名称，获取数据
    printf("%s\n", csv[2]["备注"].c_str());
    
//[7] 获取某一行数据
    Row row = csv[4];
    printf("%s\n", row["姓名"].c_str());

    return 0;
}