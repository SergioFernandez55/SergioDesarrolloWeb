#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"
#include <thread>

class HttpServer:TcpServer{
    
    private:
        const char* port;

    public:
        HttpServer();
        void start(int argc, char const *argv[]);
        void handleClientConnection(Socket& client);
    
    protected:
        void analyzeArguments();
        void handleClientConnection();

};




#endif