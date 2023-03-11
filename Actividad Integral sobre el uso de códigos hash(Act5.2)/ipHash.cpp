#include "ipHash.h"

ipHash::ipHash(){
  
}

ipHash::ipHash(std::string ipTexto, int salidas, int entradas){
  ipText = ipTexto;
  aristasaliendo = std::to_string(salidas);
  aristaLlegando = std::to_string(entradas);
}


std::string ipHash::printIpHash(){ 
  return "Ip: " + ipText + "   Grado Salida: " + aristasaliendo + "  Gardo Entrada: " + aristaLlegando;
}
