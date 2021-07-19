#ifndef HTTPAPLICATION
#define HTTPAPLICATION

#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

class HttpAplication
{
public:
	void dummyServer(HttpRequest *request, HttpResponse *response);
};

#endif