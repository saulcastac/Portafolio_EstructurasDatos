
#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "LinkedList.h"
#include "ipAddress.h"
#include "HashTable.h"
#include "ipHash.h"
#define INF 0x3f3f3f3f

class Graph {
  private:
    int numNodes;
    int numEdges;
    int indexMax;
    // Lista de adyacencia (vector de listas)
    std::vector<LinkedList<std::pair<int,int>>> adjList;
    // mapea IPs a un numero entero de orden
    std::map<unsigned int, ipAddress> mapIP;
    // vector de objetos ipAddress para contar los grados
    std::vector<ipAddress> ips;

    std::priority_queue<std::pair<int, std::string>> maxHeapIPs;
    HashTable<unsigned int, std::string> newHash;
    
    void split(std::string line, std::vector<int> & res);

  public:
    Graph();
    ~Graph();
    void loadGraphList(std::string fileName); 
    void CreateHash();
    void printGraph();
    void getIPSummary();

    
    
};




#endif // __GRAPH_H_