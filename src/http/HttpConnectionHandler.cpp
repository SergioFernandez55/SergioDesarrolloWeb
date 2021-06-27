
#include "HttpConnectionHandler.hpp"

HttpConnectionHandler::HttpConnectionHandler()
{
}

void HttpConnectionHandler::StartConnection()
{
    this->startThread();
}

void HttpConnectionHandler::handleHttpRequest(HttpRequest *request, HttpResponse *response)
{
    request->load(clientSocket);
    response->send(clientSocket);
}

int HttpConnectionHandler::run()
{
    HttpRequest *request = new HttpRequest();
    HttpResponse *response = new HttpResponse();
    this->handleHttpRequest(request, response);
    return 0;
}

void HttpConnectionHandler::setSocket(Socket &client)
{
    this->clientSocket = client;
}