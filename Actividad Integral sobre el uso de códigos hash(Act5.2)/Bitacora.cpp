#include "Bitacora.h"


Bitacora::Bitacora() {

}

Bitacora::Bitacora(std::string fileName) {
  graph.loadGraphList(fileName);
  graph.CreateHash();
  graph.getIPSummary();
}

Bitacora::~Bitacora() {

}

