#ifndef HTTPRESPONSE
#define HTTPRESPONSE

class HttpResponse{
    
    private:
        const char* port;

    public:
        start(int argc, char const *argv[]);
    
    protected:
        analyzeArguments();
        handleClientConnection();

}


#endif