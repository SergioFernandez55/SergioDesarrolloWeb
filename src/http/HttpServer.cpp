#include "HttpServer.hpp"
#include <iostream>
#include <cstdlib>

static HttpServer::HttpServer &getInstance()
{
	static HttpServer server;
	return server;
}

void HttpServer::stop()
{
	std::cout << "Server stopped" << std::endl;
	this->stopListening();
}

void HttpServer::start(int argc, char const *argv[])
{
	//upon start port gets its info from the arguments

	//agregar error para mas de 4 argumentos
	if (argc >= 2)
	{
		port = argv[1];
		if (argc > 2)
		{
			numberThreads = atoi(argv[2]);
		}
		this->listenForever(port);
	}
	else
	{
		std::cerr << "usage: httpserver PORT" << std::endl;
	}
}

void HttpServer::handleClientConnection(Socket &client)
{
	HttpConnectionHandler *connectionThread = new HttpConnectionHandler();
	connectionThread->setSocket(client);
	/*for (int i = 0; i < numberThreads; ++i)
    {*/
	connectionThread->StartConnection();
	//}s
}

void HttpServer::analyzeArguments()
{
}
