/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    graph.h
 * Author:  Joe Cooper
 ********************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stack>
#include "data.h"
#include "linkedlist.h"

using std::stack;

class Graph {
    
public:
    
    //Constructor
    Graph();
    
    //Destructor
    ~Graph();
    
    bool isEmpty();
    int getVertices();
    int getEdges();
    bool addVertex(int, string*);
    bool removeVertex(int);
    bool addEdge(Vertex, Vertex, double);
    bool removeEdge(Vertex, Vertex);
    Vertex getVertex(int, Vertex*);
    void displayAdjList();
    
private:
    struct Container {
        Vertex *head;
        Container *next;
        Container *prev;
        LinkedList edgelist;
    };
    Container *root;
    int edges;
    int vertices;
    
        
};

#endif /* GRAPH_H */

