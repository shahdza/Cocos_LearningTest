// V3.4
#include "HelloWorldScene.h"
USING_NS_CC;


// 引入头文件
#include "sqlite3.h"


// 回调函数
int callback(void* para, int col_num, char** col_value, char** col_name)
{
    CCLOG("%s : 总共有 %d 个字段", (char *)para , col_num);
    
    for (int i = 0; i < col_num; i++) {
        CCLOG("%s = %s", col_name[i], col_value[i]);
    }
    
    CCLOG("------------------------------"); // 分隔符
    
    return 0;
}


Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}


bool HelloWorld::init()
{
    if ( !Layer::init() ) return false;


//[1] 数据库路径
    std::string path = "/soft/cocos2d-x-3.4/projects/Demo34/Resources/data.db";
    std::string sql; // sql语句
    int ret;         // 执行结果，SQLITE_OK表示成功执行
    
//[2] 创建sqlite数据库
    sqlite3* pdb = nullptr;
    
//[3] 打开sqlite数据库
    ret = sqlite3_open(path.c_str(), &pdb);
    
    // 当sqllite数据库打开失败时
    if (ret != SQLITE_OK) {
        // 获得sqltite数据库打开错误的信息
        const char* errmsg = sqlite3_errmsg(pdb);
        CCLOG("sqlite open error: %s", errmsg);
        sqlite3_close(pdb);
        return false;
    }
    
//[4] 创建表
    // 创建表的sql语句：create table
    sql = "create table student(ID integer primary key autoincrement, name text, sex text)";
    
    // 执行sql语句：sqlite3_exec
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    
    if(ret != SQLITE_OK) {
        CCLOG("create table failed");
    }

//[5] 插入数据（增）
    // (1 , 'student1' , 'male')
    sql = "insert into student values(1, 'student1', 'male')";
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    if(ret != SQLITE_OK) {
        CCLOG("insert data failed!");
    }
    
    // (2 , 'student3' , 'female')
    sql = "insert into student values(2, 'student2', 'female')";
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    if(ret != SQLITE_OK) {
        CCLOG("insert data failed!");
    }
    
    // (3 , 'student3' , 'male')
    sql = "insert into student values(3, 'student3', 'male')";
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    if(ret != SQLITE_OK) {
        CCLOG("insert data failed!");
    }
    
//[6] 查询数据，使用sqlite3_exec（查）
    sql = "select * from student";
    ret = sqlite3_exec(pdb, sql.c_str(), &callback, (void*)"para", nullptr);

//[7] 删除数据（删）
    // 删除第一条记录
    sql = "delete from student where ID = 1";
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    if(ret != SQLITE_OK) {
        CCLOG("delete data failed!");
    }
    
//[8] 修改数据（改）
    // 修改第三条记录的 name 字段
    sql = "update student set name = 'hello' where ID = 3";
    ret = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, nullptr);
    if(ret != SQLITE_OK) {
        CCLOG("update data failed!");
    }
    
//[9] 查询数据，使用sqlite3_get_table（查）
    char** table; // 查询结果
    int r, c;     // 行数、列数
    
    sql = "select * from student";
    sqlite3_get_table(pdb, sql.c_str(), &table, &r, &c, nullptr);
    
    CCLOG("行数 is %d , 列数 is %d", r, c);
    
    // 第0行（0 ~ c-1），为字段名
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j < c; j++) {
            CCLOG("%s", table[i * c + j]);
        }
        CCLOG("------------------------------");
    }
    
    // 记得是否查询表
    sqlite3_free_table(table);

//[10] 记得关闭数据库，是否资源
    sqlite3_close(pdb);
    
    return true;
}

