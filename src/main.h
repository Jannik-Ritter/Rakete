#include <iostream>

using namespace std;

// utils
void logMessage(string prefix, string message);

// state functions
void onIdle();
void onStart();
void onFlying();
void onFallingDown();
void onLanded();

// data handling
void insertDataQueue(string message);
void emptyDataQueue();