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

int main(){
    Simulator simulator(20, "receiver");
    simulator.setClockFrequency(6);

    int counter = 1;
    while(simulator.receiverTransmissionNotComplete()){

        // check if there is any packet received
        if(simulator.sendAcknowledgementForPacketIfExist(counter)){
            // expect next item now
            counter++;
        }
        simulator.tick();
    }
    return 0;
}
