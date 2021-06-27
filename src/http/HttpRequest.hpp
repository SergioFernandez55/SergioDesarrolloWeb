#ifndef HTTPREQUEST
#define HTTPREQUEST

#include "HttpMessage.hpp"
#include "Socket.hpp"
enum Method
{
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH
};

class HttpRequest : HttpMessage
{

private:
    const char *port;
    string headerName;
    void getMethod(string requestMethod);

public:
    HttpRequest();
    void load(Socket socket);
    const string &getUri();

protected:
    Method method;
    string uri;
};

#endif