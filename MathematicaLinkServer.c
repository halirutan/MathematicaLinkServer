#include <stdio.h>
#include <wstp.h>

void talkToMe(WSLinkServer server, WSLINK link){
    fprintf(stderr, "Hey!!!");
    WSActivate(link);
    WSPutFunction(link,"Print",1);
    WSPutString(link, "Hello Client Program");
    WSEndPacket(link);
    WSFlush(link);
    WSClose(link);
}

int main(int argc, char **argv)
{
    WSEnvironmentParameter ep;
    WSENV env;

    env = WSInitialize((WSEnvironmentParameter)0);
    int error;
    WSLinkServer server;
    server = WSNewLinkServer(env, NULL, &error);
    if (error != WSEOK) {
        fprintf(stderr, "Something went wrong when starting up the server");
        return -1;
    }
    WSRegisterCallbackFunctionWithLinkServer(server, talkToMe);
    unsigned short port = WSPortFromLinkServer(server, &error);
    const char *interface = WSInterfaceFromLinkServer(server, &error);

    fprintf(stderr, "link = LinkConnect[\"%d\", LinkProtocol -> \"TCPIP\", LinkHost -> \"%s\"]", port, interface);

    WSWaitForNewLinkFromLinkServer(server, &error);

    WSShutdownLinkServer(server);

    WSDeinitialize(env);

    return 0;
}