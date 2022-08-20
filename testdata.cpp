/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    graph.h
 * Author:  Joe Cooper
 ********************/

#include "testdata.h"


string* testData::getString() {
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                      'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                      'y', 'z'};
    
    string str = "";
    
    for (int j = 0; j < 5; j++) {
        str += alpha[rand() % 26];
    }
    string* ranStr = &str;
    
    return ranStr;
}