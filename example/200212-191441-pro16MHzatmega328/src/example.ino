#include "RelaySwitchPB.h"
#include "Arduino.h"

#define RELAY_SWITCH_PIN 13
#define BUTTON_PIN 2

RelaySwitch relaySwitch;

void setup(){
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    relaySwitch.init(RELAY_SWITCH_PIN);
    relaySwitch.init(RELAY_SWITCH_PIN, true, true);
    relaySwitch.turnOFF();
}

void loop(){
    if(digitalRead(BUTTON_PIN)){
        relaySwitch.turnON();
    } else{
        relaySwitch.turnOFF();
    };
    delay(100);
}