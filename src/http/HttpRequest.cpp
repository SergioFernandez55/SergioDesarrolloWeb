#include "HttpRequest.hpp"
#include <string>
#include <cstring>
#include <unistd.h>

HttpRequest::HttpRequest()
{
}

void HttpRequest::load(Socket socket)
{

    string firstLine = "";
    string msg = "";
    socket.readLine(firstLine);
    string delimiter = " ";

    size_t pos = 0;
    string token[2] = {};
    int iter = 0;
    while ((pos = firstLine.find(delimiter)) != std::string::npos)
    {
        token[iter] = firstLine.substr(0, pos);
        firstLine.erase(0, pos + delimiter.length());
        ++iter;
    }
    //header.insert(token[0], token[1]);
    string type = token[0];
    string route = token[1];
    httpVersion = firstLine.substr(0, firstLine.size() - 1);
    if (type == "POST")
    {
        std::cout << "isPost" << std::endl;
        sleep(60);
    }

    headerName = "";
    string headerString = "";
    while (socket.readLine(msg))
    {
        if (msg == "\r")
        {
            break;
        }
        //std::cout << msg << std::endl;
        headerName.append(msg);
        msg = "";
    }

    string bodyString = "";
    while (socket.readLine(msg))
    {
        bodyString.append(msg);
        msg = "";
    }
    char bodyChars[bodyString.size() + 1];
    strcpy(bodyChars, bodyString.c_str());
    body << bodyChars;
    std::cout << firstLine << std::endl;
    std::cout << headerName << std::endl;
    std::cout << body.str() << std::endl;
}
// to do implement this
void HttpRequest::getMethod(string requestMethod)
{
}

const string &HttpRequest::getUri()
{
}