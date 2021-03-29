/**
 *@author: YashKumarVerma
 *@desc: main entry point of application
 *@time: Tuesday 30-March-2021 01:18:27
 **/

#include<iostream>
#include<vector>
#include"./../includes/rainbow/rainbow.h"
#include"./../includes/simulator/simulator.h"

using namespace std;

int main(){
    Simulator simulator(10, "sender");
    int counter = 1;
    while(simulator.transmissionNotComplete()){
        
        // send a packet every second
        simulator.sendDataPacket(counter++);
        
        // tick the process cycle
        simulator.tick();
    }
    return 0;
}