#include "HttpMessage.hpp"

HttpMessage::HttpMessage()
{
}

void HttpMessage::getHeaderValue(std::string key)
{
}

void HttpMessage::analyzeArguments()
{
}

void HttpMessage::handleClientConnection()
{
}

void HttpMessage::setBody(std::string newBody)
{
	body << newBody;
}
