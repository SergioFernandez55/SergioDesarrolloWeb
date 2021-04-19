#ifndef HTTPMESSAGE
#define HTTPMESSAGE

class HttpMessage{
    
    private:
        const char* port;

    public:
        HttpMessage();
        void start(int argc, char const *argv[]);
    
    protected:
        void analyzeArguments();
        void handleClientConnection();

};


#endif