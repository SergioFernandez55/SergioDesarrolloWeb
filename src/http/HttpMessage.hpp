#ifndef HTTPMESSAGE
#define HTTPMESSAGE

#include <string>
#include <iostream>
#include <map>
#include <sstream>
//using namespace std;

class HttpMessage
{

public:
	HttpMessage();
	void getHeaderValue(std::string key);
	void setBody(std::string newBody);

protected:
	std::string httpVersion;
	std::map<std::string, std::string> header;
	std::stringstream body;

	void analyzeArguments();
	void handleClientConnection();
};

#endif