
#include "HttpConnectionHandler.hpp"

        HttpConnectionHandler::HttpConnectionHandler(Socket& s){

        }
        void HttpConnectionHandler::StartConnection(){

        }
        void HttpConnectionHandler::handleHttpRequest(HttpRequest request, HttpResponse response){

        }
        int HttpConnectionHandler::run(){
            HttpRequest *request = new HttpRequest();
            HttpResponse *response = new HttpResponse();
            return 0;
        }