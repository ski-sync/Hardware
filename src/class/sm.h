#ifndef SM_H
#define SM_H

#include <Arduino.h>

enum State {
    UNKNOWN,
    IDLE,
    CONNECTED,
    DISCONNECTED,
};

class Fsm {
    State _current_state = UNKNOWN;
public:
    void checkState(State source_state, State target_state, bool condition);
    State getCurrentState();
    static String stateToString(State state);
};

extern const String state_names[]; // Declaration of the array

#endif // SM_H
