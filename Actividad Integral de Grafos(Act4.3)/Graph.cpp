#include "Graph.h"


Graph::Graph() {
  numNodes = 0;
  numEdges = 0;
}

Graph::~Graph() {
  adjList.clear();
  ips.clear();
}

void Graph::loadGraphList(std::string fileName) {
  std::string line, ip1, ip2, peso;
  int i = 0;
  std::ifstream file(fileName);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while(std::getline(file,line)) {
      if (i == 0) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[1];
        // Reservar memoria para los renglones de la lista de adyacencia (renglon 0 no utilizado) 
        adjList.resize(numNodes+1);
        ips.resize(numNodes+1);
        // Declara una lista vacia para cada renglon y la almacena en el vector
        for (int k = 1; k <= numNodes; k++) {
          LinkedList<std::pair<int,int>> tmpList; // en ponderado lista de pares
          adjList[k] = tmpList; 
        }
      }
      else if (i > 0 && i <= numNodes) {
        ipAddress tmpIP(line, "", i);
        ips[i] = tmpIP;
        mapIP.insert({tmpIP.getIpValue(), tmpIP}); // {string ip, int}
        
      } 
      else if (i > numNodes) {
        std::size_t found = line.find(":", 15);
        ip1 = line.substr(15, found-15);
        std::size_t found2 = line.find(" ", found+1);
        std::size_t found3 = line.find(":", found2+1);
        ip2 = line.substr(found2, found3-found2);
        std::size_t found4 = line.find(" ", found3+1);
        std::size_t found5 = line.find(" ", found4+1);
        peso = line.substr(found4, found5-found4);
        // Crear arista ip1 a ip2 con un peso
        ipAddress tmpIP1(ip1, "", 0);
        ipAddress tmpIP2(ip2, "", 0);
        std::map<unsigned int, ipAddress>::iterator it;
        int ip1Index, ip2Index;
        it = mapIP.find(tmpIP1.getIpValue());     
        if(it != mapIP.end())
          ip1Index = it->second.getIpIndex();
        it = mapIP.find(tmpIP2.getIpValue());     
        if(it != mapIP.end())
          ip2Index = it->second.getIpIndex();
        adjList[ip1Index].addLast({ip2Index, stoi(peso)});
        ips[ip1Index].addToDegree();
      }
      i++;
    }
    file.close();
  }
}

void Graph::outDegrees(std::string fileName) {
  std::ofstream file(fileName);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    for (int i = 1; i <= numNodes; i++) {
      file << "ip: " << ips[i].getIp() << "  grado: "  << ips[i].getDegree() << std::endl;
      maxHeapIPs.push(std::make_pair(ips[i].getDegree(), ips[i].getIp()));
    }
    
    std::pair<int, std::string> maxDegrees = maxHeapIPs.top();
    std::cout << "La ip del Bot Master es: " << maxDegrees.second << std::endl;
    std::cout << "Con un total de: "<< maxDegrees.first << " grados de salida"<<std::endl<<std::endl;
    file.close();
  }
}

void Graph::maxDegrees(std::string fileName) {
  std::ofstream file(fileName);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    // get 5 ips
    for (int i = 1; i <= 5; i++) {
      std::pair<int, std::string> p = maxHeapIPs.top(); 
      //Creamos un para para buscarlo luego en nuestro mapa
      if (i == 1){
        ipAddress tmpIP(p.second, "", 0);
        std::map<unsigned int, ipAddress>::iterator it;
        int ipIndex;
        it = mapIP.find(tmpIP.getIpValue());     
        if(it != mapIP.end())
          ipIndex = it->second.getIpIndex();
        indexMax = ipIndex;
        }
      maxHeapIPs.pop();
      file << "ip: " << p.second << "  grado: "  << p.first << std::endl;
    }
    file.close();
  }
}

void Graph::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::printGraph(){
	  std::cout << "Adjacency List" << std::endl;
		for (int u = 1; u <= numNodes; u++){
      std::cout << "vertex " << u << ": ";
      for (int j = 0; j < adjList[u].getNumElements(); j++) {
        std::pair<int, int> p = adjList[u].getData(j);
        std::cout << "{" << p.first << ", " << p.second << "} ";
      }
      std::cout << std::endl;
    }
}

void Graph::botMaster(std::string fileName){
  shortestPath(indexMax, fileName);
}

void Graph::shortestPath(int source, std::string fileName){
  std::ofstream file(fileName);
  std::priority_queue< std::pair<int, int>, std::vector <std::pair<int, int>> , std::greater<std::pair<int, int>> > pq;
  
  std::vector<int> distance(numNodes+1, INF);
  pq.push(std::make_pair(0, source));
  distance[source] = 0;
  
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    // Recorrer nodos adyacentes de u
    for (int j = 0; j < (int)adjList[u].getNumElements(); j ++) {
      std::pair<int,int> p = adjList[u].getData(j);
      int v = p.first; // vertice adj a u
      int weight = p.second; // peso de la arista
      if (distance[v] > distance[u] + weight) {
        // Updating distanceance of v
        distance[v] = distance[u] + weight;
        pq.push(std::make_pair(distance[v], v));
      }
    }
  }
  /*
  std::cout << "pq.empty " << pq.empty() << std::endl;
  std::cout << "pq.top().second " << pq.top().second << std::endl;
  */
  if(!file.good()){
    file.close();
    throw std::invalid_argument("File Not Foud");
  }
  else{
    std::pair<int, int> tmpPair;
    file << "La ip del Bot Master es: " << ips[source].getIp() << std::endl;
    file << "Ip      Distancia" << std::endl;
    for(int i = 1; i <= numNodes; i++){
      file << ips[i].getIp() << "    " << distance[i] << std::endl; 
    }
  
  std::cout <<"La IP que presumiblemente requiere más esfuerzo para que el boot master la ataque es: "<< std::endl << ips[pq.top().second].getIp() << " con una distancia de: "<< pq.top().first << " unidades" << std::endl;
    
  }
  file.close();
}