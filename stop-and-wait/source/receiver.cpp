/**
 *@author: YashKumarVerma
 *@desc: main entry point of application
 *@time: Tuesday 30-March-2021 01:18:27
 **/

#include<iostream>
#include<vector>
#include"./../includes/rainbow/rainbow.h"
#include"./../includes/simulator/simulator.h"
#include"./../includes/log/log.h"

using namespace std;


/** to facilitate creating problems in transmission based on frequency **/
bool problemCreator(float errorRate){
    int number = rand()%(11);
    return number < errorRate;
}


int main(){
    srand(time(0));

    /** simulator configurations **/
    int error_rate = 3;
    int total_packets = 10;
    float simulator_frequency = 1.0;


    Simulator simulator(total_packets, "receiver");
    simulator.setClockFrequency(simulator_frequency);
    simulator.setErrorRate(error_rate);

    int counter = 1;
    while(simulator.receiverTransmissionNotComplete()){

        /** simulate acknowledgement loss **/
        if(problemCreator(simulator.errorRate)){
            log::receiver_error("acknowledgement lost for packet # " + to_string(counter));
        }
        // check if there is any packet received
        if(simulator.sendAcknowledgementForPacketIfExist(counter)){
            // expect next item now
            counter++;
        }
        simulator.tick();
    }
    return 0;
}