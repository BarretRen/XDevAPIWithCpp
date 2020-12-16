//使用X DevAPI连接数据库，并返回session实例
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    //利用大括号，session在括号结束时自动close连接并释放资源
    {
        // Session sess("localhost", 33060, "barret", "shidandan1230");
        SessionSettings settings(SessionOption::HOST, "localhost", SessionOption::PORT, 33060);
        settings.set(SessionOption::USER, "barret");
        settings.set(SessionOption::PWD, "shidandan1230");
        Session sess(settings);
        Schema db = sess.getSchema("world_x"); //获取数据库
        // or Schema db(sess, "test");
    }
}