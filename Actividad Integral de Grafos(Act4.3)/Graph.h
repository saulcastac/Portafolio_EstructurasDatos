
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
    // Priority queue para ordenar los ips según su distancia 
    std::priority_queue<std::pair<int, std::string>> maxHeapIPs;

    void split(std::string line, std::vector<int> & res);
    void shortestPath(int, std::string);
  public:
    Graph();
    ~Graph();
    void loadGraphList(std::string fileName);
    void printGraph();
    void outDegrees(std::string fileName);
    void maxDegrees(std::string fileName);
    void botMaster(std::string);
    
    
};




#endif // __GRAPH_H_