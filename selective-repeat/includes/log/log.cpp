/**
 *@author: YashKumarVerma
 *@desc: log definitions
 *@time: Tuesday 30-March-2021 02:26:25
 **/

#include<iostream>
#include<vector>

// load signatures
#include"log.h"

using namespace std;

void log::sender_info(string message){
    cout << rainbow::green("[sender] ") << rainbow::grey(message) << endl;
}

void log::sender_error(string message){
        cout << rainbow::bold(rainbow::red("[sender] ")) << rainbow::bold(rainbow::red(message))<< endl;
}

void log::receiver_info(string message){
        cout << rainbow::green("[receiver] ") << rainbow::grey(message)<< endl;
}

void log::receiver_error(string message){
        cout << rainbow::bold(rainbow::red("[receiver] ")) << rainbow::bold(rainbow::red(message))<< endl;
}
    