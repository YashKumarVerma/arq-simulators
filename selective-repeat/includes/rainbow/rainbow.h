#ifndef RAINBOW
#define RAINBOW

#include<string>

using namespace std;

class rainbow{
    public:
        static string orange(string str);
        static string green(string str); 
        static string red(string str);
        static string grey(string str);
		static string bold(string str);
		static string italic(string str);
		static string underline(string str);
		static string strike(string str);
};

#endif