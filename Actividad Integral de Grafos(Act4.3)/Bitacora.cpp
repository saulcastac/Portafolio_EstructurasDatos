#include "Bitacora.h"


Bitacora::Bitacora() {

}

Bitacora::Bitacora(std::string fileName) {
  graph.loadGraphList(fileName);
  //graph.printGraph();
  graph.outDegrees("grados_ips.txt");
  graph.maxDegrees("mayores_grados_ips.txt");
  graph.botMaster("distancia_bootmaster.txt");
}

Bitacora::~Bitacora() {

}

