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
    Simulator simulator(10, "sender");
    int counter = 1;
    while(simulator.senderTransmissionNotComplete()){

       if(simulator.waiting == false){
            simulator.sendDataPacket(counter++);
            simulator.halt();
       }else{
            log::sender_info("waiting for acknowledgement");
       }
       
        // tick the process cycle
        simulator.tick();
    }
    return 0;
}