#ifndef HTTPREQUEST
#define HTTPREQUEST



class HttpRequest{
    
    private:
        const char* port;

    public:
        HttpRequest();
        void start(int argc, char const *argv[]);
    
    protected:
        void analyzeArguments();
        void handleClientConnection();

};


#endif