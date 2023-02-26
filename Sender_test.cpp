#include <string>
#include "test/catch.hpp"
#include "Sender.h"
#include "SensorConstants.h"

TEST_CASE("SensorBase abstraction validation"){
    int testSID = 0;
    char testPtr[SIDBUFFER];
    SECTION("Use of unhandled SID at constructor"){
        testSID = 4;
        SensorBase sTest(testSID);
        REQUIRE(sTest.initialize()==false);
        REQUIRE(sTest.disable()==false);
    }
    SECTION("Edge Cases of Sensor parameter interfaces"){
        testSID = 0;
        SensorBase sTest(testSID);
        REQUIRE(sTest.initialize()==true);
        // null pointer handling
        REQUIRE(sTest.getID(nullptr, SIDBUFFER) == false);
        // wrong buffer size handling
        const int WRONGSIDBUFFER = 3;
        REQUIRE(sTest.getID(testPtr, WRONGSIDBUFFER) == false);        
        REQUIRE(sTest.disable()==true);
    }
    SECTION("Propper Case of sensor interface"){
        testSID = 1;
        SensorBase sTest(testSID);
        REQUIRE(sTest.initialize()==true);
        REQUIRE(sTest.getID(testPtr, SIDBUFFER));
        std::string finder(testPtr);
        REQUIRE(finder.find("SID") != std::string::npos);
        REQUIRE(finder.find(std::to_string(testSID)) != std::string::npos);
        REQUIRE(sTest.getSample(testPtr, PARAMSBUFFER));
        finder = std::string(testPtr);
        REQUIRE(finder.find("cRate") != std::string::npos);
        REQUIRE(finder.find("temp")  != std::string::npos);
        REQUIRE(sTest.disable()==true);
    }
}