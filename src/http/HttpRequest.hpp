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

class HttpRequest : public HttpMessage
{

private:
	const char *port;
	std::string headerName;
	void getMethod(std::string requestMethod);

public:
	HttpRequest();
	void load(Socket socket);
	const std::string &getUri();

protected:
	Method method;
	std::string uri;
};

#endif