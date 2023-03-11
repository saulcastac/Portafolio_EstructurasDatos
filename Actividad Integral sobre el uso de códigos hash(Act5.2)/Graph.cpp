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
        ips[ip2Index].addToInDegree();      
      }
      i++;
    }
    file.close();
  }
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

void Graph::CreateHash(){
  newHash.reSize(numNodes+1);
  for(int i = 1; i <= numNodes; i++){
    ipHash tmpIpHash(ips[i].getIp(), ips[i].getDegree(), ips[i].getInDegree());
    newHash.add(ips[i].getIpValue(), tmpIpHash.printIpHash());
  }
  newHash.overflowSize();
}

void Graph::getIPSummary(){
  std::string ip;
  int valido = 0;
  std::cout << "Bienvenido a la bitacora con Hash " << std::endl;
  while(valido == 0){
    std::cout << "Porfavor ingrese una Ip y validaremos si esta en la bitacora: ";
    std::cin >> ip;
    
    for(int i = 1; i <= numNodes; i++){
      if(ip == ips[i].getIp()){
        std::cout << "Ip encontrada!" << std::endl;
        std::cout << newHash.getDataAt(newHash.getHashIndex(ips[i].getIpValue())) << std::endl;
        std::cout << "Esta Ip ha accesado a: " << std::endl;
        for(int j = 0; j < adjList[i].getNumElements(); j++){
          std::pair<int, int> p = adjList[i].getData(j);
          std::cout << "{" << ips[p.first].getIp() << ", " << p.second << "}" << std::endl;
        }
        valido = 1;
      }
      else if(i == numNodes && valido != 1){
        std::cout << "Ip no encontrada, introduzca una nueva Ip valida" << std::endl;
        valido = 0;
      }
    }
  }
}