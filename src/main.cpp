#include <Arduino.h>
#include <iostream>
#include <unistd.h>
using namespace std;

// main functions
void setup();
void logMessage(string prefix, string message);

//state functions
void onIdle();
void onStart();
void onFlying();
void onFallingDown();
void onLanded();

// data handling
void insertDataQueue(string message);
void emptyDataQueue();

// utility

// constants
const string STATE_IDLE_MESSAGE = "Raketenstatus -> Idle";
const string STATE_START_MESSAGE = "Raketenstatus -> Start";
const string STATE_FLYING_MESSAGE = "Raketenstatus -> Fliegend";
const string STATE_FALLING_DOWN_MESSAGE = "Raketenstatus -> Fallend";
const string STATE_LANDED_MESSAGE = "Raketenstatus -> Gelandet";
const string SUCCESSFULLY_LANDED = "Raketenladung erfolgreich";

const string STATE_PREFIX = "[STATE] "; 
const string LOG_PREFIX = "[LOGGER] "; 
const string LOG_SUFFIX = "; ";

const int IDLE_INTERVAL = 1;

// describes the life-cycle states the rocket will enter in order 
enum procedureState {idle, start, flying, fallingDown, landed};

string dataQueue[] = {};

// logs a message given a prefix and a message
void logMessage(string prefix, string message){
    string combined = prefix + message;
    cout << combined + LOG_SUFFIX;
}

// describes the rocket state and handles switching between states
// also fires callbacks and logs all actions
class rocketState {
    public:
        void setState(procedureState newState){
            curState = newState;

            // TODO add all callbacks
            switch(newState){
                case idle:
                    logMessage(STATE_PREFIX, STATE_IDLE_MESSAGE);
                    onIdle();
                    return;
                
                case start:
                    logMessage(STATE_PREFIX, STATE_START_MESSAGE);
                    onStart();
                    return;
                
                case flying:
                    logMessage(STATE_PREFIX, STATE_FLYING_MESSAGE);
                    onFlying();
                    return;
                
                case fallingDown:
                    logMessage(STATE_PREFIX, STATE_FALLING_DOWN_MESSAGE);
                    onFallingDown();
                    return;
                
                case landed:
                    logMessage(STATE_PREFIX, STATE_LANDED_MESSAGE);
                    onLanded();
                    return;
            }
        }
    private:
        procedureState curState;
};

// send all queued data to the reciever
// should be called in a regular interval to avoid jams
void emptyDataQueue(){
    int curSize = sizeof dataQueue;

    for (int i = 0; i < curSize; i++){
        string entry = dataQueue[i];

        // TODO send to reciever
    }
};

// inserts a message into the data queue to be sent at a lter time
void insertDataQueue(string message){
    int curSize = sizeof dataQueue;
    int newIndex = curSize + 1;
    
    dataQueue[newIndex] = message;
}

// 
void onIdle(){
    sleep(IDLE_INTERVAL);
}

// 
void onStart(){
    
}

// 
void onFlying(){
    
}

// 
void onFallingDown(){
    
}

// 
void onLanded(){
    
}

// intial check
void setup(){
    printf("Test");
    rocketState state;
    
    for (int i = idle; i < 6; i++){
        procedureState curState = static_cast<procedureState>(i);
        state.setState(curState);
    }

    logMessage(LOG_PREFIX, SUCCESSFULLY_LANDED);
}

// while wait(1)
void loop() {
    emptyDataQueue();  
}