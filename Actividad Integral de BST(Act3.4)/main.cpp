/*
* Equipo:
* Saúl Castañeda
* Yahir Rivera
* Luisa Castaños
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
*/
#include "Bitacora.h"

int main(){
    
  // Objeto de la clase Bitacora
  Bitacora Nuevo_registro;
  
  // Llamamos al metodo leer archivo
  Nuevo_registro.leerArchivo("bitacoraHeap.txt");
  
  // Guarda los datos de tipo registro acomodados por Ip en un archivo
  Nuevo_registro.nuevoArchivo();
  
  // Crea el contador de accesos junto con el BST y los odena por ip de mayor a menor, también despliega las 5 ip's con mayores accesos
  Nuevo_registro.contadorAccesos();
  return 0;
}