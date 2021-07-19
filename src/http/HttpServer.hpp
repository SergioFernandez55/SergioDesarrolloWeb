#ifndef HTTPSERVER
#define HTTPSERVER

#include "TcpServer.hpp"
#include "HttpConnectionHandler.hpp"
#include "Thread.hpp"
#include <thread>

class HttpServer : TcpServer
{
	DISABLE_COPY(HttpServer);

private:
	const char *port;
	int numberThreads;

public:
	HttpServer() = default;
	~HttpServer() = default;

	//dejar implementacion de metodos en cpp
	static HttpServer &getInstance();

	void stop();

	void start(int argc, char const *argv[]);
	void handleClientConnection(Socket &client) override;

protected:
	void analyzeArguments();
};
#endif