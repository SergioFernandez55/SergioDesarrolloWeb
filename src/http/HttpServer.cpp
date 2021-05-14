#include "HttpServer.hpp"
#include <iostream>

void HttpServer::start(int argc, char const *argv[]){
    //upon start port gets its info from the arguments
    if(argc >= 2){
        port = argv[1];
        this -> listenForever(port);
    }
    else{
        std::cerr << "usage: httpserver PORT" << std::endl;
    }
}


void HttpServer::handleClientConnection(Socket& client){
    HttpConnectionHandler *connectionThread = new HttpConnectionHandler(client);
    connectionThread->run();
}

void HttpServer::analyzeArguments(){

}

