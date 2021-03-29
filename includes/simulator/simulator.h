/**
 *@author: YashKumarVerma
 *@desc: class signature for signature
 *@time: Tuesday 30-March-2021 01:27:52
 **/
#ifndef SIMULATOR
#define SIMULATOR

#include<iostream>


using namespace std;

class Simulator {
    private:
        int totalCount;
        int sentCount;
        int frequency;

    public:
        // declare simulator environment
        Simulator(int packets, string name);

        // get details about packet transmission
        int getPacketsLeft();
        int getPacketsSent();

        // set behavior about packet transmission
        void setClockFrequency(int seconds);

        // to check if transmission is complete or not
        bool transmissionNotComplete();

        // bool
        void tick();


        /**
         * functions to be consumed by sender clients
         */

        // to get next data element
        void sendDataPacket(int packetIndex);

        /** utility functions for general usage **/
        string packetName(int packetIndex){
            return to_string(packetIndex) + ".txt";
        }
        
};


#endif