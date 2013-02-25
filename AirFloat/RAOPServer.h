//
//  RAOPServer.h
//  AirFloatCF
//
//  Created by Kristian Trenskow on 5/10/11.
//  Copyright 2011 The Famous Software Company. All rights reserved.
//

#ifndef __RAOPSERVER_H
#define __RAOPSERVER_H

#include <pthread.h>

extern "C" {
#include "sockaddr.h"
#include "webserver.h"
}

class WebConnection;

class RAOPServer {
    
public:
    RAOPServer(uint16_t port);
    ~RAOPServer();

    bool startServer();
    void waitServer();
    void stopServer();
    
    bool isRunning();
    
    struct sockaddr* getLocalEndPoint();
    uint32_t getConnectionCount();
    
    static const char* localhostConnectedErrorNotificationName;
    
private:
    
    static bool _acceptConnectionCallback(web_server_p server, web_connection_p newConnection, void* ctx);
    
    uint16_t _port;
    
    web_server_p _server;
    
};

#endif