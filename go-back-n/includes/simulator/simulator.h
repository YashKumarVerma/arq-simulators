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
        int transmittedCount;
        int receivedCount;
        int frequency;

    public:
        bool waiting;

        // declare simulator environment
        Simulator(int packets, string name);

        // get details about packet transmission
        int getPacketsSentBySender();
        int getPacketsLeftWithSender();

        // set behavior about packet transmission
        void setClockFrequency(int seconds);
        void setState(string state);

        // to check if transmission is complete or not
        bool senderTransmissionNotComplete();
        bool receiverTransmissionNotComplete();

        // bool
        void tick();
        
        // state modifiers
        void halt();
        void release();

        /**
         * functions to be consumed by sender clients
         */

        // to get next data element
        void sendDataPacket(int packetIndex);
        bool acceptAcknowledgementIfExist(int packetIndex);
        bool sendAcknowledgementForPacketIfExist(int packetIndex);
        void abandonPacket(int packetIndex);

        /** utility functions for general usage **/
        string packetName(int packetIndex){
            return to_string(packetIndex) + ".txt";
        }

        string ackName(int packetIndex){
            return to_string(packetIndex) + ".ack";
        }

        string receivedName(int packetIndex){
            return to_string(packetIndex) + ".done";
        }
        
};


#endif