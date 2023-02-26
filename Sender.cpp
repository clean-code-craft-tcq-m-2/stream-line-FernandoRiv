#include <string.h>
#include "Sender.h"
#include "SensorConstants.h"
#ifdef UTEST
#define CATCH_CONFIG_RUNNER
#include "test/catch.hpp"
#endif // UTEST

const static int MESSAGECOUNT = 50;

bool Sender::formatMessage(int sensorIndex){
    outputBuffer[0]=0; //resets array for formatMessage's strcat
    if(Sensors.at(sensorIndex)->getID(sIDBuffer, SIDBUFFER)){
        strcat(outputBuffer,sIDBuffer);
        if(Sensors.at(sensorIndex)->getSample(paramsBuffer, PARAMSBUFFER)){
            strcat(outputBuffer,paramsBuffer);
            return true;
        } 
    }
    return false;
}

bool Sender::sendMessage(){
    printf("%s\n", outputBuffer);
    return true;
}

bool Sender::initialize(){
    for(auto sensor : Sensors){
        if(!sensor->initialize())
            return false;
    }
    return true;
}

bool Sender::disable(){
    for(auto sensor : Sensors){
        if(!sensor->disable()){
            delete sensor;
            return false;
        }
    }
    return true;
}

int main(){
    Sender sender(2);
    SensorBase* sensorptr;
    SensorBase Sensor1(SENSOR0ID);
    sensorptr = &Sensor1;
    sender.Sensors.push_back(sensorptr);
    SensorBase Sensor2(SENSOR1ID);
    sensorptr = &Sensor2;
    sender.Sensors.push_back(sensorptr);
    sender.initialize();
    for(int i = 0; i < MESSAGECOUNT; ++i){
        for(int j = 0; j<static_cast<int>(sender.Sensors.size()); ++j){
            sender.formatMessage(j);
            sender.sendMessage();
        }
    }
    sender.disable();

    #ifdef UTEST
    Catch::Session().run();
    #endif // UTEST

    return 0;
}