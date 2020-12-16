//使用API提供的函数读取表内容，这里不是用原始SQL
//注意与例4的区别
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

        Schema db = sess.getSchema("world_x");
        Table city = db.getTable("city"); //获取数据表
        RowResult rs = city.select("ID", "Name", "CountryCode").where("ID < 10").execute();

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