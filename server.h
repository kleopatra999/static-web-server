#ifndef SERVER_H
#define SERVER_H

#include <string>

using namespace std;


static string ip;
static int port;
static string dir;




class Server
{
public:
    Server();
    static void start(string ip_, int port_, string dir_);
    static void restart();
    static void stop();
};

#endif // SERVER_H
