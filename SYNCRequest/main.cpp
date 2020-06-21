#include "Client.h"
#include "ace/Init_ACE.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
//#include "ace/ACE_OS.h"


int main(int argc,char* argv[])
{
	//using namespace ACE;

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
