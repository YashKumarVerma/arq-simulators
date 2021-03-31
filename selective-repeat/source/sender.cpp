/**
 *@author: YashKumarVerma
 *@desc: main entry point of application
 *@time: Tuesday 30-March-2021 01:18:27
 **/

#include<iostream>
#include<vector>

#include<ctime>
#include<cstdio>

#include"./../includes/rainbow/rainbow.h"
#include"./../includes/simulator/simulator.h"
#include"./../includes/log/log.h"

using namespace std;

/** to facilitate creating problems in transmission based on frequency **/
bool problemCreator(float errorRate){
    int number = rand()%(11);
    return number < errorRate;
}

/** main function **/
int main(){
    srand(time(0));
    
    /** set the fraction of error rate. This is applied on all operations **/
    int error_rate = 3;
    int total_packets = 10;
    float simulator_frequency = 1.0;

    /** set window size **/
    int n = 4;

    /** set max timeout limit **/
    int max_timeout_range = 10; 
    int timeout = 0;
    
    /** all configurations end here, now application codebase **/
    Simulator simulator(total_packets, "sender");
    simulator.setClockFrequency(simulator_frequency);
    simulator.setErrorRate(error_rate);
    
    // anchor contains how many items have been successfully transmitted
    int anchor = 1;

    // lower and upper to keep track of sliding window
    int lower = 1;
    int upper = lower + n;
    
    /** initialize total packets**/
    vector<int>verifiedDeliveryTable(total_packets+1, 0);


    // till we get callback for each packet
    while(simulator.senderTransmissionNotComplete()){
        
        while(lower <= total_packets){

            /** this simulates packet loss **/
            if(problemCreator(simulator.errorRate)){
                log::sender_error("Error sending packet " + to_string(lower));
                lower++;
            }
            simulator.sendDataPacket(lower++);
        }
       
        //    the first element of sliding window is verified 
        while(simulator.acceptAcknowledgementIfExist(anchor)){
            log::sender_info("Received acknowledgement for #" + to_string(anchor));
            verifiedDeliveryTable.at(anchor) = 1;
            anchor++;
            timeout = 0;
        }

        if(anchor == total_packets){
            break;
        }
        
        if(timeout < max_timeout_range){
            timeout++;
            log::sender_info("Waiting for acknowledgement for packet #" + to_string(anchor) + ", timeout = " + to_string(timeout));
        }
        else{
            /** do nothing, just send the first missing acknowledgment index **/
            for(int i=0; i<total_packets; i++){
                if(verifiedDeliveryTable.at(i) == 0){
                    simulator.sendDataPacket(i);
                    log::sender_error("Request timed out, resending individual packet " + to_string(i));
                }
            }

            timeout = 0;
        }

        simulator.resendNegativeAcknowledgement();
        // tick the process cycle
        simulator.tick();
    }
    return 0;
}