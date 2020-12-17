//使用CRUD函数，并用bind绑定参数
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
        Table city = db.getTable("country");
        //使用1，bind绑定参数
        // RowResult rs = city.select().where("Name = :param1").bind("param1", "China").execute();

        //使用2，可以通过bind和execute将一个操作重复执行多次：
        auto statement = city.select().where("Name = :param1");
        RowResult rs = statement.bind("param1", "China").execute();
        for (auto it = rs.begin(); it != rs.end(); ++it)
        {
            cout << (*it).get(0).get<std::string>() << " ";
            cout << (*it).get(1).get<std::string>() << " ";
            cout << (*it).get(2).get<int>() << " ";
            cout << (*it).get(3).get<std::string>();
            cout << endl;
        }
        rs = statement.bind("param1", "United States").execute();
        for (auto it = rs.begin(); it != rs.end(); ++it)
        {
            cout << (*it).get(0).get<std::string>() << " ";
            cout << (*it).get(1).get<std::string>() << " ";
            cout << (*it).get(2).get<int>() << " ";
            cout << (*it).get(3).get<std::string>();
            cout << endl;
        }
    }
    catch (const Error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}