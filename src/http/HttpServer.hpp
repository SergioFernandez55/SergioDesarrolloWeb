#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"
#include "HttpConnectionHandler.hpp"
#include <thread>

class HttpServer:TcpServer{
    
    private:
        const char* port;

    public:
        HttpServer();
        ~HttpServer();
        void start(int argc, char const *argv[]);
        void handleClientConnection(Socket& client);
    
    protected:
        void analyzeArguments();
        void handleClientConnection();

};




#endif