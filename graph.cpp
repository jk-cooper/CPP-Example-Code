/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    graph.h
 * Author:  Joe Cooper
 ********************/

#include "graph.h"

Graph::Graph() {
    root = NULL;
    edges = 0;
    vertices = 0;
}

Graph::~Graph() {
    
}

bool Graph::isEmpty() {
    bool result = true;
    if (getVertices() > 0) {
        result = false;
    }
    return result;
}

int Graph::getVertices() {
    return vertices;
}

int Graph::getEdges() {
    return edges;
}

bool Graph::addVertex(int id, string* info) {
    bool result = false;
    if (id > 0 && *info != "\0") {
        if (!root) {
            root = new Container;
            root->head = new Vertex;
            root->head->data.id = id;
            root->head->data.info = *info;
            root->head->data.weight = 0.0;
            root->next = NULL;
        }
        Container* current = root;
        if (id == current->head->data.id) result = false;
        while (current && id != current->head->data.id) {
            if (!current->next && id != current->head->data.id) {
            Container* add = new Container;
            add->head = new Vertex;
            add->head->data.id = id;
            add->head->data.info = *info;
            add->head->data.weight = 0.0;
            current->next = add;               
            }
        current = current->next;
        }
        vertices++;
        result = true;
        }
    return result;
}

bool Graph::removeVertex(int remove) {
    bool result = false;
    Container* temp = new Container;
    if (root->head->data.id == remove) {
        temp = root;
        root = root->next;
        result = true;
    }
    Container* current = root;
    while (current) {
        if (!current->next) {
            temp = current->next;
            current->next = NULL;
        }
        else if (current->next->head->data.id == remove) {
            current->edgelist.clearList();
            temp = current->next;
            current->next = current->next->next;
            result = true;
        } else {
            current = current->next;
        }
        if (current->edgelist.exists(remove)) {
            current->edgelist.deleteNode(remove);
        }
        current = current->next;
    }
    delete temp;
    vertices--;
    return result;
}

bool Graph::addEdge(Vertex source, Vertex destination, double cost) {
    bool result = false;
    Container* current = root;
    while (current && source.data.id != destination.data.id) {
        if (source.data.id == current->head->data.id) {
            current->edgelist.addNode(destination.data.id, &destination.data.info, cost);
        }
        else if (destination.data.id == current->head->data.id) {
            result = current->edgelist.addNode(source.data.id, &source.data.info, cost);
            if (result) edges++;
        } else {
            result = false;
        }
        current = current->next;
    }
    return result;
}

bool Graph::removeEdge(Vertex source, Vertex destination) {
    bool result = false;
    Container* current = root;
    if (getEdges() > 0) {
        while (current) {
            if (source.data.id == current->head->data.id) {
                current->edgelist.deleteNode(destination.data.id);
            }
            if (destination.data.id == current->head->data.id) {
                result = current->edgelist.deleteNode(source.data.id);
                if (result) edges--;
            }
            current = current->next;
        }        
    } else {
        result = false;
    }
    return result;
}

Vertex Graph::getVertex(int id, Vertex* getVertex) {
    if (id > 0) {
        Container* current = root;
        while (current) {
            if (current->head->data.id == id) {
                getVertex->data.id = current->head->data.id;
                getVertex->data.info = current->head->data.info;
            } 
        current = current->next;
        }
    }
    return *getVertex;
}

void Graph::displayAdjList() {
    Container* current = root;
    while (current) {
        std::cout << current->head->data.id << " : " << 
                     current->head->data.info;
                     current->edgelist.printList(); 
                     std::cout << std::endl;
        current = current->next;
    }
}
