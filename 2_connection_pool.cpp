//使用connection pool，避免数据库连接的反复创建
#include <iostream>
#include <mysqlx/xdevapi.h>
using namespace std;
using namespace mysqlx;

int main()
{
    /*
    ( "mysqlx://user:password@host_name/db_name",
       ClientOption::POOLING, true,
       ClientOption::POOL_MAX_SIZE, max_connections,
       ClientOption::POOL_QUEUE_TIMEOUT, std::chrono::seconds(100),
       ClientOption::POOL_MAX_IDLE_TIME, std::chrono::microseconds(1)
    */
    Client cli("mysqlx://barret:shidandan1230@localhost/world_x", ClientOption::POOL_MAX_SIZE, 7);
    Session sess = cli.getSession();
    // use Session sess as usual
    cli.close(); // close all Sessions
}