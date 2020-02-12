#include "RelaySwitchPB.h"
#include "Arduino.h"

RelaySwitchPB::RelaySwitchPB(){
    this->stateON = false;
}

void RelaySwitchPB::turnON(){
    this->stateON = true;
    setState(true);
}

void RelaySwitchPB::turnOFF(){
    stateON = false;
    setState(false);
}


void RelaySwitchPB::setState(bool on){
    if(on != invertedOutput){
        digitalWrite(relayPin, HIGH);
    } else{
        digitalWrite(relayPin, LOW);
    }
}

bool RelaySwitchPB::isStateOn(){
    return stateON;
}

void RelaySwitchPB::invertInterpreter(bool NOConnection, bool invertedOutput){
    this->invertedOutput = !NOConnection != invertedOutput;
}

void RelaySwitchPB::test(){
    turnON();
    delay(1000);
    turnOFF();
}

void RelaySwitchPB::init(uint8_t relayPin, bool NOConnection, bool invertedOutput){
    this->relayPin = relayPin;
    invertInterpreter(NOConnection, invertedOutput);
    pinMode(relayPin, OUTPUT);
    turnOFF();
}