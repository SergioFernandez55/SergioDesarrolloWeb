#ifndef HTTPRESPONSE
#define HTTPRESPONSE

#include "Socket.hpp"
#include "HttpMessage.hpp"
class HttpResponse:HttpMessage{
    
    private:
        const char* port;

    public:
        HttpResponse();
        void setStatusCode(int code, string reason);
        void addHeader(string key,  string value);
        void send(Socket& socket);
    
    protected:
        int statusCode;
        string reason;


};


#endif