#include "Client.h"

int main(int argc,char* argv[])
{
    ACE::init();
    CScheduler server;
    CProxy proxy(&server);
    CClient cli(&proxy);

    server.open(0);
    cli.open(0);

    getchar();
    cli.SetExit();
    
    ACE::fini();

    return 0;
}