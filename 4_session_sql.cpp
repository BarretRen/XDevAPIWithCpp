//使用session的sql函数，执行原始SQL语句
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    try
    {
        Session sess("localhost", 33060, "barret", "shidandan1230");
        cout << "Session accepted, creating collection..." << endl;

        sess.sql("use world_x").execute(); //使用url不需要这句
        //执行一个select语句并打印结果
        RowResult rs = sess.sql("SELECT ID, Name, CountryCode FROM city where ID <10").execute();
        for (auto it = rs.begin(); it != rs.end(); ++it)
        {
            cout << (*it).get(0).get<int>() << " ";
            cout << (*it).get(1).get<std::string>() << " ";
            cout << (*it).get(2).get<std::string>();
            cout << endl;
        }
    }
    catch (const Error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}