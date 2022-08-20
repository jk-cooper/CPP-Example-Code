/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    data.h
 * Author:  Joe Cooper
 ********************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string info;
    double weight;
};

struct Vertex {
    Data data;
    Vertex *next;
    Vertex *prev;
};

#endif /* DATA_H */

