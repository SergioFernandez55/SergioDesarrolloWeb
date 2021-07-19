#include "HttpApplication.hpp"

void HttpAplication::dummyServer(HttpRequest *request, HttpResponse *response)
{
	response->setBody("dummy body");
}