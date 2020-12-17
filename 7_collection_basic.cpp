//通过API使用collection document store
//基本的CRUD操作
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    try
    {
        Session sess("localhost", 33060, "barret", "shidandan1230");
        Schema db = sess.getSchema("test");
        //创建新的collection
        Collection coll = db.createCollection("my_collection");
        //插入几行json document
        coll.add(R"({"name":"barret","age":30})").execute();
        coll.add(R"({"name":"dandan","age":28})").execute();
        coll.add(R"({"name":"paopao","age":3})").execute();
        //查询数据
        DocResult docs = coll.find("age < :param1")
                             .bind("param1", 30)
                             .execute();
        //打印结果
        cout << docs.fetchOne() << endl;
        //删除collection
        db.dropCollection("my_collection");
    }
    catch (const Error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}