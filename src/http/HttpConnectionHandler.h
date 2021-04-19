#ifndef HTTPCONNECTIONHANDLER
#define HTTPCONNECTIONHANDLER

#include "Thread.hpp"

class HttpConnectionHandler::Thread{
    
    public:
        HttpConnectionHandler();
        void StartConnection();
        void handleHttpRequest(HttpRequest request, HttpResponse response);

};

#endif