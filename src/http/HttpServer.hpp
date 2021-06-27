#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"
#include "HttpConnectionHandler.hpp"
#include "Thread.hpp"
#include <thread>

class HttpServer : TcpServer
{
    DISABLE_COPY(HttpServer);

private:
    const char *port;
    int numberThreads;

public:
    HttpServer() = default;
    ~HttpServer() = default;

    //dejar implementacion de metodos en cpp
    static HttpServer &getInstance()
    {
        static HttpServer server;
        return server;
    }

    void stop()
    {
        std::cout << "Server stopped" << std::endl;
        this->stopListening();
    }

    void start(int argc, char const *argv[]);
    void handleClientConnection(Socket &client) override;

protected:
    void analyzeArguments();
};
#endif