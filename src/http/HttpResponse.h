#ifndef HTTPRESPONSE
#define HTTPRESPONSE


class HttpResponse{
    
    private:
        const char* port;

    public:
        HttpResponse();
        void start(int argc, char const *argv[]);
    
    protected:
        void analyzeArguments();
        void handleClientConnection();

};


#endif