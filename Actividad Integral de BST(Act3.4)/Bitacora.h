#ifndef _BITACORA_H_
#define _BITACORA_H_

  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include <vector>
  #include <stdexcept>
  #include "Registro.h"
  #include "priorityHeap.h"
  #include "Toto.h"

  class Bitacora {
    private:
      // Crea el vector de tipo Registro
      std::vector<Registro> listaRegistros;

      // Variables
      std::string month, day, hours, minutes, seconds, ipAdd, port, error;
      int iteraciones, repetidos, acum;

      // Metodos
      void heapify(int, int);
      void heapSort(int);
      
    public:
      // Constructor
      Bitacora();

      // Método que lee el archivo
      void leerArchivo(std::string Archivo_a_leer);
      
      // Métodos que nos proporcionan información de la lista
      int getSize(); // Tamaño de la lista
      void print();  // Imprime la lista 
      
      //Método que escribe el nuevo archivo
      void nuevoArchivo();

      // Método para generar BST y contabilizar los accesos
      void contadorAccesos();
      int parent(int);
      void imprimeAccesos();
      
  };

#endif
