#ifndef HTTPCONNECTIONHANDLER
#define HTTPCONNECTIONHANDLER

#include "Thread.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "Socket.hpp"

class HttpConnectionHandler : Thread
{

public:
    HttpConnectionHandler();
    void StartConnection();
    void handleHttpRequest(HttpRequest *request, HttpResponse *response);
    int run() override;
    void setSocket(Socket &client);

private:
    Socket clientSocket;
};

#endif