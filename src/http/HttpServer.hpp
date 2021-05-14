#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"
#include "HttpConnectionHandler.hpp"
#include <thread>

class HttpServer:TcpServer{
    DISABLE_COPY(HttpServer);
    
    private:
        const char* port;

    public:
        HttpServer() = default;
        ~HttpServer() = default;

        static HttpServer& getInstance(){
            static HttpServer server;
            return server;
        }

        void stop(){
            std::cout << "Server stopped" << std::endl;
            this->stopListening();
        }

        void start(int argc, char const *argv[]);
        void handleClientConnection(Socket& client) override;

    protected:
        void analyzeArguments();

};
#endif