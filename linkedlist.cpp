/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    linkedlist.cpp
 * Author:  Joe Cooper
 ********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string* data, double weight) {
    bool result = false;
    if (id > 0 && *data != "\0") {
        if(!head) {
            head = new Vertex;
            head->data.id = id;
            head->data.info = *data;
            head->data.weight = weight;
            head->next = NULL;
            head->prev = NULL;
            result = true;
        }
        Vertex* current = head;
        while(current) {
            if (id != current->data.id) {
                addUnique(id, *data, weight);
                result = true;
            }
            current = current->next;
        }        
    }
    return result;
}

bool LinkedList::deleteNode(int delNode) {
    bool deleted = false;
    if(delNode > 0) {
        Vertex* current = head;
        while (current && !deleted) {
            if (current->data.id == delNode) {
                Vertex *deletedNode = current;
                if(deletedNode->prev && deletedNode->next) { // item in middle
                    deletedNode->prev->next = deletedNode->next;
                    deletedNode->next->prev = deletedNode->prev;
                } else if(deletedNode->next) { // item is at head, make new head
                    head = deletedNode->next;
                    head->prev = NULL;
                } else if(deletedNode->prev) { // item is at tail, change tail
                    deletedNode->prev->next = NULL;
                } else if(!deletedNode->prev && !deletedNode->next) {
                    head = NULL;
                }
                delete deletedNode;
                deleted = true;
            }
            current = current->next;
        }        
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data* data) {
    bool result = false;
    if(head && id > 0) { 
        Vertex* current = head;
        while(current) {
            if(id == current->data.id) {
                *data = current->data;
                result = true; // node found, return status as true
            }
            else {
                data->id = -1;
                data->info = "";
            }
            current = current->next;
        }
    }
    return result;
}

void LinkedList::printList(bool backward) {    
    struct Vertex* current = new Vertex;
    current = head;
    if (backward == false) {
        while (current) {
            std::cout << " --> " << current->data.id << " : " << 
                         current->data.info << " (" << current->data.weight << 
                         ") ";
            current = current->next;
        }
    }
    if (backward == true) {
        std::stack<Vertex*> stk; // Push nodes onto a stack to print LIFO
        Vertex* elem = head;
        while (elem) {
            stk.push(elem);
            elem = elem->next;
        }
        while (!stk.empty()) {
            elem = stk.top();
            std::cout << " --> " << elem->data.id << " : " << elem->data.info <<
                         " (" << elem->data.weight << ") ";
            stk.pop();
        }
    }
}

int LinkedList::getCount() {
    if(!head) { // Return 0 if the list is empty
        return 0;
    }
    int count = 1;
    Vertex *current = head;
    while(current->next) {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList() {
    bool result = true;
    Vertex *current = head;
    while(current) {
        Vertex* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    return result;
}

bool LinkedList::exists(int num) {
    Vertex* current = head;
    while (current) {
        if (current->data.id == num) {
            return true; // while id matches confirm item is in list
        }
        current = current->next;
    }
    // If we reach the end of the list the item does not exist
    return false;
}

void LinkedList::addUnique(int id, string data, double weight) {
    Vertex* current = head;
    bool added = false;
    while (current && !added && id != current->data.id) {
        struct Vertex* newNode = new Vertex;
        newNode->data.id = id;
        newNode->data.info = data;
        newNode->data.weight = weight;
        newNode->next = NULL;
        newNode->prev = NULL;   
        if (id < current->data.id && id != current->data.id) {
            if(current->prev) { // Link current node previous to newNode
                current->prev->next = newNode;
                newNode->prev = current->prev;
            } else { // Reset head node if current has no previous
                head = newNode;
            }
            newNode->next = current;
            current->prev = newNode;
            added = true;
        } else if (!current->next) { // Add new node to tail no next node
            current->next = newNode;
            newNode->prev = current;
            added = true;
        }
        current = current->next;
    }
}