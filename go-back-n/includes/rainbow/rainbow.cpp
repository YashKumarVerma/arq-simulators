#include<string>
#include"rainbow.h"


std::string rainbow::orange(std::string str){
    std::string x;
    x.append("\e[33m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

std::string rainbow::green(std::string str){
    std::string x;
    x.append("\e[32m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

std::string rainbow::grey(std::string str){
    std::string x;
    x.append("\e[90m");
    x.append(str);
    x.append("\e[0m");
    return x;
}


std::string rainbow::red(std::string str){
    std::string x;
    x.append("\e[31m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

std::string rainbow::bold(std::string str){
	std::string x;
	x.append("\033[1m");
	x.append(str);
	x.append("\033[0m");
	return x;
}

std::string rainbow::italic(std::string str){
	std::string x;
	x.append("\e[3m");
	x.append(str);
	x.append("\e[0m");
	return x;
}

std::string rainbow::underline(std::string str){
	std::string x;
	x.append("\e[4m");
	x.append(str);
	x.append("\e[0m");
	return x;
}

std::string rainbow::strike(std::string str){
	std::string x;
	x.append("\e[9m");
	x.append(str);
	x.append("\e[0m");
	return x;
}