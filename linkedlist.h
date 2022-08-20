/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    linkedlist.h
 * Author:  Joe Cooper
 ********************/

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include "data.h"
#include <stack>

using std::stack;

class LinkedList {
    
    public:
        
        //Constructor
        LinkedList();
        
        //Destructor
        ~LinkedList();
        
        bool addNode(int, string*, double);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool=false);
        int getCount();
        bool clearList();
        bool exists(int);
        
    private:
        Vertex *head;
        
        void addUnique(int, string, double);
        
};

#endif /* LINKEDLIST_LINKEDLIST_H */