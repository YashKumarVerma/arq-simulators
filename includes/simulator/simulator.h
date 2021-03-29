/**
 *@author: YashKumarVerma
 *@desc: class signature for signature
 *@time: Tuesday 30-March-2021 01:27:52
 **/

#include<iostream>

using namespace std;

class Simulator {
    private:
        int totalCount;
        int sentCount;
        int frequency;

    public:
        // declare simulator environment
        Simulator(int packets);

        // get details about packet transmission
        int getPacketsLeft();
        int getPacketsSent();

        // set behavior about packet transmission
        void setClockFrequency(int seconds);

        // to check if transmission is complete or not
        bool isTransmissionComplete();

        // bool
        void tick();
};
