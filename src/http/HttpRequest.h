#ifndef HTTPREQUEST
#define HTTPREQUEST

class HttpRequest{
    
    private:
        const char* port;

    public:
        start(int argc, char const *argv[]);
    
    protected:
        analyzeArguments();
        handleClientConnection();

}


#endif