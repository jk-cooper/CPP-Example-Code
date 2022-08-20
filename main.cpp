/********************
 * Name: Joe Cooper
 * Coding Final Project
 * Purpose: Creating a working bi-directional weighted graph class
 * File:    main.cpp
 * Author:  Joe Cooper
 ********************/

#include "main.h"
#include "graph.h"
#include "testdata.h"


int main(int argc, char** argv) {

    srand(time(NULL));
  
    Graph testGraph;
    
    testData getData;

    Vertex *p;    
    Vertex foo[MAXVERTICES];

    p = foo;
    
    for (int i = 0; i < MAXVERTICES; i++) {

        foo[i].data.id = rand() % 100;
        foo[i].data.info = *(getData.getString());
        foo[i].data.weight = 0.0;
        foo[i].next = NULL;
        foo[i].prev = NULL;
    }

    std::cout << "Test data to be loaded to graph: " << std::endl;
    
    for (int i = 0; i < MAXVERTICES; i++) {
        std::cout << foo[i].data.id << " : " << foo[i].data.info << std::endl;
    }
    
    std::cout << std::endl << "Testing addEdge" << std::endl;
    std::cout << "---------------------------------------" << std::endl;    
    
    for (Vertex vertex : foo) {
        std::cout << "Success = 1, Fail = 0: " << testGraph.addVertex(vertex.data.id, &vertex.data.info) << std::endl;
    }
    
    std::cout << std::endl << "Printing the adjacency list" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    testGraph.displayAdjList();
    
    std::cout << std::endl << "Testing addEdge" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    for (int i = 0; i < MAXVERTICES; i++) {
        int sourceIndex = rand() % MAXVERTICES;
        Vertex sourceAdd = foo[sourceIndex];
        int destinationIndex = rand() % MAXVERTICES;
        Vertex destAdd = foo[destinationIndex];
        double cost = rand() % 100;
        std::cout << "Adding edge from " << sourceAdd.data.id << " to " << destAdd.data.id << "." << std::endl;        
        std::cout << "Success = 1, Fail = 0: " << testGraph.addEdge(sourceAdd, destAdd, cost) << std::endl;    
    }
    

    
    
    
    std::cout << std::endl << "Printing the adjacency list" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    testGraph.displayAdjList();
    
    std::cout << std::endl << "Testing remove edge" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    int sourceIndex = rand() % MAXVERTICES;
    Vertex sourceRemove = foo[sourceIndex];
    int destinationIndex = rand() % MAXVERTICES;
    Vertex destRemove = foo[destinationIndex];
    
    std::cout << "Removing edge from " << sourceRemove.data.id << " to " << destRemove.data.id << "." << std::endl;

    std::cout << "Success = 1, Fail = 0: " << testGraph.removeEdge(sourceRemove, destRemove) << std::endl;
    
    std::cout << std::endl << "Printing the adjacency list" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    testGraph.displayAdjList();    
    
    std::cout << std::endl << "Testing remove vertex" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    int removeIndex = rand() % MAXVERTICES;
    int remove = foo[removeIndex].data.id;
    
    std::cout << remove << " is the ID to remove." << std::endl;

    std::cout << "Success = 1, Fail = 0: " << testGraph.removeVertex(remove) << std::endl;
    
    std::cout << std::endl << "Printing the adjacency list" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    testGraph.displayAdjList(); 
    
    std::cout << std::endl << "Testing getEdges functionality" << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;
    
    
    std::cout << testGraph.getEdges() << std::endl << std::endl;

    std::cout << std::endl << "Testing getVertices functionality" << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;
    
    
    std::cout << testGraph.getVertices() << std::endl << std::endl;

    
    std::cout << std::endl << "Testing isEmpty functionality" << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;
    
    if (!testGraph.isEmpty()) {
        std::cout << "testGraph is empty" << std::endl;
    } else {
        std::cout << "testGraph is NOT empty" << std::endl;
    }
    
    std::cout << std::endl << "Testing getVertex functionality" << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;
    
    Vertex* testVertex = new Vertex;
    
    int testGetIndex = rand() % MAXVERTICES;
    Vertex testGet = foo[testGetIndex];
    
    std::cout << "ID to test getVertex: " << foo[testGetIndex].data.id << std::endl << std::endl;
    
    testGraph.getVertex(testGet.data.id, &*testVertex);
    
    if (testVertex->data.id > 0) {
        std::cout << "testVertex's id is: " << testVertex->data.id << std::endl <<
                     "testVertex's info is: " << testVertex->data.info  << std::endl;        
    } else {
        std::cout << "No vertex in graph with that ID" << std::endl;
    }

    
    string testAddVertexStr = "kagaklng";
    
        // Random operations of hashtable methods with print after to show results
    
    std::cout << std::endl << "Testing with random numbers and random method calls"  << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;

    
    for (int i = 0; i < MAXVERTICES*3; i++) {
        testAddVertexStr += "adfg";
        int testAddVertexID = rand() % MAXVERTICES;
        int testRemoveVertexID = rand() % MAXVERTICES;
        int ranIndex = rand() % MAXVERTICES; 
        int sourceIndex = rand() % MAXVERTICES;
        int destinationIndex = rand() % MAXVERTICES;        
        Vertex sourceAdd = foo[sourceIndex];
        Vertex destAdd = foo[destinationIndex];
        double cost = rand() % 100;
        Vertex sourceRemove = foo[sourceIndex];
        Vertex destRemove = foo[destinationIndex];
        Vertex* testVertex = new Vertex;
        int testGetIndex = rand() % MAXVERTICES;
        Vertex testGet = foo[testGetIndex];
        int ranSwitch = rand() % 7;
        switch(ranSwitch) {
            case 0: std::cout << "Getting # of vertices: " << 
                                 testGraph.getVertices() <<
                                 std::endl; break;
            case 1: std::cout << "Getting " << foo[testGetIndex].data.id << std::endl;
                                 testGraph.getVertex(testGet.data.id, &*testVertex);
                                 std::cout << "testVertex's id = " << testVertex->data.id <<
                                 std::endl <<
                                 "testVertex's info = " << testVertex->data.info <<
                                 std::endl; break;
            case 2: std::cout << "Getting # of edges: " << 
                                 testGraph.getEdges() <<
                                 std::endl; break;
            case 3: std::cout << "Adding vertex " << foo[ranIndex].data.id << " : " << 
                                 " 1 = success, 0 = fail: " <<
                                 testGraph.addVertex(testAddVertexID, &testAddVertexStr) <<
                                 std::endl << std::endl << "Getting vertex count: " << 
                                 testGraph.getVertices() <<
                                 std::endl; 
                                 break;
            case 4: std::cout << "Removing vertex" << foo[ranIndex].data.id << " : " <<
                                 " 1 = success, 0 = fail: " << 
                                 testGraph.removeVertex(testRemoveVertexID) << 
                                 std::endl << std::endl << "Getting vertex count: " << 
                                 testGraph.getVertices() <<
                                 std::endl; break;
            case 5: std::cout << "Adding edge from " << sourceAdd.data.id << " to " <<
                                 destAdd.data.id << " 1 = success, 0 = fail: " << 
                                 testGraph.addEdge(sourceAdd, destAdd, cost) << 
                                 std::endl << std::endl << "Getting edge count: " << 
                                 testGraph.getEdges() <<
                                 std::endl; break;
            case 6: std::cout << "Removing edge from " << sourceRemove.data.id << " to " <<
                                 destRemove.data.id << " 1 = success, 0 = fail: " << 
                                 testGraph.removeEdge(sourceRemove, destRemove) << 
                                 std::endl << std::endl << "Getting edge count: " << 
                                 testGraph.getEdges() <<
                                 std::endl; break;
        }
        std::cout << std::endl;
    }
    
    testGraph.displayAdjList();
    
    return 0;
}

