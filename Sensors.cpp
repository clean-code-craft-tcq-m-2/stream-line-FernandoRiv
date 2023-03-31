#include <iostream>
#include <string.h>
#include "Sensors.h"
#include "SensorConstants.h"

bool SensorBase::initialize(){
    if(sensorID < MAXSAMPLEFILES){
        sensorInputs.open(readings[sensorID], std::ifstream::in);
        if(sensorInputs.good()){
            return true;
        }
    }
    printf("SensorBase::initialize() = ERROR: Failed reading input!\n");
    return false;
}

bool SensorBase::disable(){
    sensorInputs.close();
    if(!sensorInputs.good()){
        printf("SensorBase::disable() = ERROR: Failed closing input!\n");
        return false;
    }
    return true;
}

bool SensorBase::getID(char* sID, int buffSize){
    if((sID != nullptr) && (buffSize >= SIDBUFFSIZE)){
        if(snprintf(sID, SIDBUFFSIZE, "SID, %d,", sensorID)>=0){
            return true;
        }
    }
    return false;
}

bool SensorBase::getSample(char* sample, int buffSize){
    if((sample != nullptr) && (buffSize >= SAMPLEBUFFSIZE)){
        if(sampleIndex < MAXSENSORSAMPLES){
            sensorInputs.getline(readBuffer, MAXSENSORREADBUFFER);
            if(sensorInputs.good()){
                strncpy(sample, readBuffer, SAMPLEBUFFSIZE);
                sampleIndex++;
                return true;
            }
        }
    }
    return false;
}