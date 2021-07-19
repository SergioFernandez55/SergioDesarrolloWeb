#ifndef HTTPRESPONSE
#define HTTPRESPONSE

#include "Socket.hpp"
#include "HttpMessage.hpp"
class HttpResponse : public HttpMessage
{

private:
	const char *port;

public:
	HttpResponse();
	void setStatusCode(int code, std::string reason);
	void addHeader(std::string key, std::string value);
	void send(Socket &socket);

protected:
	int statusCode;
	std::string reason;
};

#endif