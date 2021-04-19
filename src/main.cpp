#include "HttpServer.hpp"

int main(int argc, char const *argv[])
{
    HttpServer *server = new HttpServer();
    server -> start(argc, argv);
    return 0;
}