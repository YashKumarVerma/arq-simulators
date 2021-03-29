/**
 *@author: YashKumarVerma
 *@desc: simulator class for generic operations
 *@time: Tuesday 30-March-2021 01:27:25
 **/

#include<iostream>
#include<vector>
#include <chrono>
#include <thread>

// peer services
#include"./../rainbow/rainbow.h"

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