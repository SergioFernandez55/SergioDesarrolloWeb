#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"

class HttpServer::TcpServer{
    
    private:
        const char* port;

    public:
        start(int argc, char const *argv[]);
    
    protected:
        analyzeArguments();
        handleClientConnection();

}


#endif