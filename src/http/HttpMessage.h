#ifndef HTTPMESSAGE
#define HTTPMESSAGE

class HttpMessage{
    
    private:
        const char* port;

    public:
        start(int argc, char const *argv[]);
    
    protected:
        analyzeArguments();
        handleClientConnection();

}


#endif