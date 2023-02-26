#ifndef _Sensor_H_
#define _Sensor_H_
#include <string>
#include <fstream>

const static int MAXSENSORSAMPLES = 50;
const static int MAXSENSORREADBUFFER = 50;
const static int MAXSAMPLEFILES = 2;
const std::string delimiter = ",";
const std::string readings[] = {
    "./Samples/Sensor1TestSamples.csv",
    "./Samples/Sensor2TestSamples.csv"
};

class SensorBase{
    private:
        int sensorID = 0;
        char readBuffer[MAXSENSORREADBUFFER];
        std::ifstream sensorInputs;
        std::uint32_t sampleIndex = 0;
    public:
        SensorBase(int sID):
            sensorID(sID)
        {};

        bool initialize();
        bool disable();
        bool getID(char* sensorID, int buffSize);
        bool getSample(char* sample, int buffSize);
};

#endif // _Sensor_Base_H_