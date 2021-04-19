#include "HttpServer.h"


HttpServer::HttpServer(){

}


void HttpServer::start(int argc, char const *argv[]){
    //upon start port gets its info from the arguments
    port = argv[0];

    this -> listenForever(port);
}

void handleClientConnection(Socket& client){
    
}

void HttpServer::analyzeArguments(){

}
void HttpServer::handleClientConnection(){

}
