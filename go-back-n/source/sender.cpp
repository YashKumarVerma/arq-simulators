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
    Simulator simulator(20, "sender");
    simulator.setClockFrequency(2);

    int n = 4;
    int max_timeout_range = 10; 
    int timeout = 0;
    
    // anchor contains how many items have been successfully transmitted
    int anchor = 1;

    // lower and upper to keep track of sliding window
    int lower = 1;
    int upper = lower + n;
    

    // till we get callback for each packet
    while(simulator.senderTransmissionNotComplete()){
        
        while(lower < upper){
            simulator.sendDataPacket(lower++);
        }
       
        //    the first element of sliding window is verified 
        if(simulator.acceptAcknowledgementIfExist(anchor)){
            log::sender_info("Received acknowledgement for #" + lower);
            upper++;
            anchor++;
        }

        if(timeout < max_timeout_range){
            timeout++;
            log::sender_info("Waiting for acknowledgement for packet #" + to_string(anchor) + ", timeout = " + to_string(timeout));
        }else{
            // trigger request burst again
            lower = anchor;
            upper = lower + n;
            timeout = 0;

            for(int i=anchor; i<upper; i++){
                simulator.abandonPacket(i);
            }
            log::sender_error("Request timed out, sending packets from " + to_string(lower) + " to " + to_string(upper));
        }

        // tick the process cycle
        simulator.tick();
    }
    return 0;
}