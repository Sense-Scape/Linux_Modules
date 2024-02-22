#ifndef LINUX_MULTI_CLIENT_TCP_TX_MODULE_TESTS
#define LINUX_MULTI_CLIENT_TCP_TX_MODULE_TESTS

#include "doctest.h"
#include "LinuxMultiClientTCPTxModule.h"


TEST_CASE("Linux MultiClient TCP TxModule Test")
{
   
    std::string sIPAddress = "127.0.0.1";
    std::string sTCPPort = "10000";
    int iDatagramSize = 512;
    unsigned uBufferSize = 10;

    LinuxMultiClientTCPTxModule linuxMultiClientTCPTxModule(sIPAddress, sTCPPort, iDatagramSize, uBufferSize);
    linuxMultiClientTCPTxModule.SetTestMode(true);
    

    SUBCASE("Constructor test") {
        CHECK(linuxMultiClientTCPTxModule.GetModuleType() == ModuleType::LinuxMultiClientTCPTxModule);
    }

}

#endif
