#ifndef LOG
#define LOG

/**
 *@author: YashKumarVerma
 *@desc: logging library signature
 *@time: Tuesday 30-March-2021 02:19:17
 **/

#include<iostream>
#include<vector>

// peer services
#include"./../rainbow/rainbow.h"

using namespace std;

class log {
    public:
    static void sender_info(string message);
    static void sender_error(string message);
    static void receiver_info(string message);
    static void receiver_error(string message);
};

#endif