#include "HttpServer.hpp"
#include "TcpServer.hpp"


void handleSignal(int signal) {
    try{
        HttpServer::getInstance().stop();
    } catch (std::runtime_error& error){

    }
}

void randomPrint(string toPrint) 
{
        std::cout<< toPrint << std::endl;
}



int main(int argc, char const *argv[]) {
    std::thread tr (randomPrint, "Correct");

    tr.join();
    //HttpServer *server = new HttpServer();
    //server -> start(argc, argv);
    //delete server;
    if(argc >= 2){
        HttpServer::getInstance().start(argc, argv);
    }
    return 0;
}