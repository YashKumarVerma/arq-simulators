/**
 *@author: YashKumarVerma
 *@desc: simulator class for generic operations
 *@time: Tuesday 30-March-2021 01:27:25
 **/

#include<iostream>
#include<vector>
#include<fstream>

// for time management
#include <chrono>
#include <thread>

// for file operations
#include <cstdio>
#include <cstring>
#include <cerrno>

// c++ 17 filesystems

// peer services
#include"./../rainbow/rainbow.h"
#include"./../log/log.h"
#include"./../simulator/simulator.h"

// load class definitions
#include"simulator.h"

using namespace std;

// utility function to create a copy of file
void copy(string from, string to){
    std::ifstream  src(from, std::ios::binary);
    std::ofstream  dst(to,   std::ios::binary);
    dst << src.rdbuf();
}

// set number of packets in system
Simulator::Simulator(int packets, string name){
    this->totalCount = packets;
    this->receivedCount = 0;
    this->transmittedCount = 0;
    this->frequency = 1;
    this->waiting = false;
    cout << rainbow::underline(rainbow::bold("ARQ Simulator :: " + name)) << endl << endl; 
    cout << rainbow::italic(rainbow::green("by Yash Kumar Verma")) << endl<< endl; 
}

// to change clock frequency as needed
void Simulator::setClockFrequency(int seconds){
    this->frequency = seconds;
}

void Simulator::halt(){
    this->waiting = true;
}

void Simulator::release(){
    this->waiting = false;
}

/**
 * Getters for data members
 */
int Simulator::getPacketsSentBySender(){
    return this->transmittedCount;
}

int Simulator::getPacketsLeftWithSender(){
    return this->totalCount - this->transmittedCount;
}


// returns true if transmission is complete
bool Simulator::senderTransmissionNotComplete(){
    return this->receivedCount != this->totalCount;
}

bool Simulator::receiverTransmissionNotComplete(){
    return this->totalCount != this->receivedCount;
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
            this->transmittedCount++;
        }


    }catch(...){
        // do not kill process if transmission failed
        log::sender_error("error sending packet : " + to_string(packetIndex));
    }
}

bool Simulator::acceptAcknowledgementIfExist(int packetIndex){
    try{
        // send acknowledgement for packet in channel
        if(rename(
            string("./channel/"+this->ackName(packetIndex)).c_str(),
            string("./channel/"+this->receivedName(packetIndex)).c_str()
        ) < 0 ) {
            log::receiver_info("waiting for ack of packet #" + to_string(packetIndex));
            return false;
        }else{
            // if packet moved to transmission medium, update local state
            log::receiver_info("ack received for packet #" + to_string(packetIndex));
            this->receivedCount++;
            return true;
        }
    }catch(...){
        log::receiver_error("error sending ack : " + to_string(packetIndex));
        return false;
    }
}

bool Simulator::sendAcknowledgementForPacketIfExist(int packetIndex){
    try{
        // send acknowledgement for packet in channel
        if(rename(
            string("./channel/"+this->packetName(packetIndex)).c_str(),
            string("./channel/"+this->ackName(packetIndex)).c_str()
        ) < 0 ) {
            return false;
        }else{
            // if packet moved to transmission medium, update local state
            log::receiver_info("ack being transmitted  :" + this->ackName(packetIndex));
            this->transmittedCount++;
            return true;
        }
    }catch(...){
        log::receiver_error("error sending ack : " + to_string(packetIndex));
        return false;
    }
}


void Simulator::abandonPacket(int packetIndex){
    try{
        copy("./channel/"+this->packetName(packetIndex),"./sender/"+this->packetName(packetIndex));
        log::sender_info("Discard old packet #" + to_string(packetIndex));
    }catch(...){
        log::sender_error("Error Discard old packet #" + to_string(packetIndex));
    }
}