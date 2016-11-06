#pragma once
#include <iostream>
#include <string>

inline void printerror(std::string text) {
	std::cout << ">:" << text << std::endl;
}

inline void printerror(const char* text) {
	std::cout << ">:" << text << std::endl;
}