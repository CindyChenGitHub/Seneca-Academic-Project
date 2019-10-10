/********************************************************************** 
// OOP244 Workshop 1: Compiling modular source code 
// File tools.h 
// Version 1.0 
// Date 2018/01/10 
// Author Cindy Chen 
/**********************************************************************/ 
#ifndef SICT_TOOLS_H 
#define SICT_TOOLS_H 
// Your header file content goes here 
namespace sict {
    // Displays the user interface menu
    int menu();
    // Performs a fool-proof integer entry
    int getInt(int min, int max);
}
#endif