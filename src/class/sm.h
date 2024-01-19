#ifndef SM_H
#define SM_H

#include <Arduino.h>

enum State {
    UNKNOWN,
    IDLE,
    CONNECTED,
    DISCONNECTED,
};

String state_names[] = {
    "UNKNOWN",
    "IDLE",
    "CONNECTED",
    "DISCONNECTED",
};

class Fsm {
    State _current_state = UNKNOWN;
public:
    void checkState(State source_state, State target_state, bool condition);
    State getCurrentState();
    static String stateToString(State state);
};

#endif // SM_H
