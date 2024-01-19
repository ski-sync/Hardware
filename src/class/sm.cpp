#include <Arduino.h> // Include the Arduino core functions.
#include "sm.h" // Include the header file that declares the State enum.

const String state_names[] = {
    "UNKNOWN",
    "IDLE",
    "CONNECTED",
    "DISCONNECTED",
};

void Fsm::checkState(State source_state, State target_state, bool condition) {
    if (source_state == _current_state && condition) {
        _current_state = target_state;
        Serial.print("Source state :");
        Serial.println(stateToString(source_state));
        Serial.print("Target state :");
        Serial.println(stateToString(target_state));
        Serial.println("--------");
    }
}

State Fsm::getCurrentState() {
    return _current_state;
}

String Fsm::stateToString(State state) {
    return state_names[state];
}