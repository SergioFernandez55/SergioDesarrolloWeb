#include "HttpServer.hpp"

int main(int argc, char const *argv[])
{
    HttpServer *server = new HttpServer();
    server -> start(argc, argv);
    delete server;
    return 0;
}