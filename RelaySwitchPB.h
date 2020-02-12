#ifndef RELAYSWITCHPB_H
#define RELAYSWITCHPB_H
#include <inttypes.h>

//NOConnection true when device is connected to NO
//invertedOutput true when led connected to pin 13 != led on relay switch, false if ==
class RelaySwitchPB{
    public:
        RelaySwitchPB();
        void init(uint8_t relayPin, bool NCConection = true, bool invertedOutput = true);    //default values for relay switch (?, true, true)
        void test();
        void turnON();
        void turnOFF();
        bool isStateOn();
    private:
        uint8_t relayPin;
        bool stateON;
        bool invertedOutput;
        void setState(bool on);
        void invertInterpreter(bool NOConnection, bool invertedOutput);
};

#endif
