#include <stdlib.h>
#include <iostream>
#include <signal.h>

#include "app.hpp"

app* _app;

void terminate(int)
{
    _app->stop();
}

int main(int argc, char** argv)
{
    signal(SIGINT, terminate);
    unsigned short port = 80;
    if(argc == 2)
        port = atoi(argv[1]);
    std::cout << "Starting on " << port << std::endl;
    app a(port);
    _app=&a;

    a.join();
}
