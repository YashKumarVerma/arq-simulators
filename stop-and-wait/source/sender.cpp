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

    /** set the fraction of error rate. This is applied on all operations **/
    int error_rate = 3;
    int total_packets = 10;
    float simulator_frequency = 1.0;


    /** all configurations end here, now application codebase **/
    Simulator simulator(total_packets, "sender");
    simulator.setClockFrequency(simulator_frequency);
    simulator.setErrorRate(error_rate);
    

    int counter = 1;
    while(simulator.senderTransmissionNotComplete()){

       if(simulator.waiting == false){
            /** this simulates packet loss **/
            if(problemCreator(simulator.errorRate)){
                log::sender_error("Packet loss encountered, packet # " + to_string(counter));
                counter++;
            }

            simulator.sendDataPacket(counter++);
            simulator.halt();
       }
       simulator.acceptAcknowledgementIfExist(counter-1);
       
        // tick the process cycle
        simulator.tick();
    }
    return 0;
}