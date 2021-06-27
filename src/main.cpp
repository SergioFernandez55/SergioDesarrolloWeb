#include "HttpServer.hpp"
#include "TcpServer.hpp"

void handleSignal(int signal)
{
    try
    {
        HttpServer::getInstance().stop();
    }
    catch (std::runtime_error &error)
    {
        //agregar mensaje de error
    }
}

int main(int argc, char const *argv[])
{

    //HttpServer *server = new HttpServer();
    //server -> start(argc, argv);
    //delete server;
    if (argc >= 2)
    {
        HttpServer::getInstance().start(argc, argv);
    }
    return 0;
}