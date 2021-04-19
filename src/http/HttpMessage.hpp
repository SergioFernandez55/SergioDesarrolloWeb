#ifndef HTTPMESSAGE
#define HTTPMESSAGE

#include <string>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

class HttpMessage{
    
    public:
        HttpMessage();
        void getHeaderValue(string key);
    
    protected:
        string httpVersion;
        map<string, string> header;
        stringstream body;

        void analyzeArguments();
        void handleClientConnection();

};


#endif