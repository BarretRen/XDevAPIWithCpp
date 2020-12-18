//通过API进行事务原子操作的处理
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    Session session("localhost", 33060, "barret", "shidandan1230");
    Schema db = session.getSchema("test");
    // Create a new collection
    Collection myColl = db.createCollection("my_collection");
    // Start a transaction
    session.startTransaction();//启动事务
    try
    {
        myColl.add(R"({"name": "Rohit", "age": 18, "height": 1.76})").execute();
        myColl.add(R"({"name": "Misaki", "age": 24, "height": 1.65})").execute();
        myColl.add(R"({"name": "Leon", "age": 39, "height": 1.9})").execute();
        session.commit();//提交事务
        cout << "Data inserted successfully." << endl;
    }
    catch (const Error &err)
    {
        // Rollback the transaction in case of an error
        session.rollback();//回退事务
        // Printing the error message
        cout << "Data could not be inserted: " << err << endl;
    }
    return 0;
}