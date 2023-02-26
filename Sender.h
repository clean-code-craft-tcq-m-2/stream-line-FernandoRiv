#ifndef _Sender_H_
#define _Sender_H_
#include <vector>
#include "Sensors.h"

const static int MESSAGEBUFFER = 100;
const static int SIDBUFFER = 20;
const static int PARAMSBUFFER = 50;

class Sender{
    private:
        int sensorCount = 0;
        char outputBuffer[MESSAGEBUFFER];
        char sIDBuffer[SIDBUFFER];
        char paramsBuffer[PARAMSBUFFER];
    public:
        std::vector<SensorBase*>Sensors;
        
        Sender(int sCount = 2):
            sensorCount(sCount)
        {
            Sensors.reserve(sCount);
        };

        bool formatMessage(int sensorIndex);
        bool sendMessage();
        bool initialize();
        bool disable();
};

#endif // _Sender_H_