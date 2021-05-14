#ifndef HTTPCONNECTIONHANDLER
#define HTTPCONNECTIONHANDLER

#include "Thread.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "Socket.hpp"

class HttpConnectionHandler:Thread{
    
    public:
        HttpConnectionHandler(Socket& s);
        void StartConnection();
        void handleHttpRequest(HttpRequest request, HttpResponse response);
        int run();
    
    private:
        Socket clientSocket;

};

#endif