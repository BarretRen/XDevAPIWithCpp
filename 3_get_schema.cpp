// 通过session获取database的schema对象
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    {
        Session sess("localhost", 33060, "barret", "shidandan1230");
        //获取所有的数据库并打印name
        std::list<Schema> schemaList = sess.getSchemas();
        cout << "Available schemas in this session:" << endl;
        for (Schema schema : schemaList)
        {
            cout << schema.getName() << endl;
        }
        Schema db = sess.getSchema("world_x"); //获取指定数据库
        Table table = db.getTable("city");//获取表
        cout<<"row count of city table is "<<table.count()<<endl;
    }
}