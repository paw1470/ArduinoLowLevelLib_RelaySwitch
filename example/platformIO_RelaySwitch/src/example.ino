#include "RelaySwitchPB.h"
#include "Arduino.h"

#define RELAY_SWITCH_PIN 13
#define BUTTON_PIN 2

RelaySwitchPB relaySwitch;

void setup(){
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    relaySwitch.init(RELAY_SWITCH_PIN);
    relaySwitch.init(RELAY_SWITCH_PIN, true, true);
    relaySwitch.turnOFF();
}

void loop(){
    if(isButtonPressed()){
        relaySwitch.turnON();
    } else{
        relaySwitch.turnOFF();
    };
    delay(100);
}

bool isButtonPressed(){
    return !digitalRead(BUTTON_PIN);
}