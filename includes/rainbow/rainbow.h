#ifndef RAINBOW
#define RAINBOW

#include<string>

class rainbow{
    public:
        static std::string orange(std::string str);
        static std::string green(std::string str); 
        static std::string red(std::string str);
        static std::string grey(std::string str);
		static std::string bold(std::string str);
		static std::string italic(std::string str);
		static std::string underline(std::string str);
		static std::string strike(std::string str);
};

#endif