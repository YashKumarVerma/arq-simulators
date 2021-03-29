/**
 *@author: YashKumarVerma
 *@desc: simulator class for generic operations
 *@time: Tuesday 30-March-2021 01:27:25
 **/

#include<iostream>
#include<vector>

// for time management
#include <chrono>
#include <thread>

// for file operations
#include <cstdio>
#include <cstring>
#include <cerrno>

// peer services
#include"./../rainbow/rainbow.h"
#include"./../log/log.h"
#include"./../simulator/simulator.h"

// load class definitions
#include"simulator.h"

using namespace std;


// set number of packets in system
Simulator::Simulator(int packets, string name){
    this->totalCount = packets;
    this->sentCount = 0;
    this->frequency = 1;
    cout << rainbow::underline(rainbow::bold("ARQ Simulator :: " + name)) << endl << endl; 
    cout << rainbow::italic(rainbow::green("by Yash Kumar Verma")) << endl<< endl; 
}

// to change clock frequency as needed
void Simulator::setClockFrequency(int seconds){
    this->frequency = seconds;
}


/**
 * Getters for data members
 */
int Simulator::getPacketsSent(){
    return this->sentCount;
}

int Simulator::getPacketsLeft(){
    return this->totalCount - this->sentCount;
}


// returns true if transmission is complete
bool Simulator::transmissionNotComplete(){
    return this->sentCount != this->totalCount;
}

// to tick the clock
void Simulator::tick(){
    std::this_thread::sleep_for(std::chrono::milliseconds(this->frequency * 1000));
}

/**
 * methods to be consumed by sender clients
 */
void Simulator::sendDataPacket(int packetIndex){
    try{
        log::sender_info("attempting to send packet :" + this->packetName(packetIndex));
        
        // try moving packet into transmission medium
        if(rename(
            string("./sender/"+this->packetName(packetIndex)).c_str(),
            string("./channel/"+this->packetName(packetIndex)).c_str()
        ) < 0 ) {
            log::sender_error("error sending packet : " + to_string(packetIndex));
        }else{

            // if packet moved to transmission medium, update local state
            log::sender_info("packet being transmitted  :" + this->packetName(packetIndex));
            this->sentCount++;
        }


    }catch(...){
        // do not kill process if transmission failed
        log::sender_error("error sending packet : " + to_string(packetIndex));
    }
}