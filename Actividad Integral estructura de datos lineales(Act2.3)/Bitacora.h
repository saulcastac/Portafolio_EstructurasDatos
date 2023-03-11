#ifndef _BITACORA_H_
#define _BITACORA_H_
  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include <vector>
  #include "Registro.h"
  #include "DLinkedList.h"

  // 
  class Bitacora {
    private:
      DLinkedList <Registro> listaRegistros;
      //std::vector<Registro> listaRegistros;//Crea el vector de tipo Registro
      std::string linea, campo, horaCompleta;//Para la lectura del archivo

    public:
      //Constructor
      Bitacora();

      //Método que lee el archivo
      void leerArchivo(std::string Archivo_a_leer);

      //Lo que nos proporciona información de la lista
      int getSize();//no da el numElemnts
      void print();

      //Métodos para la busqueda
      void busquedaFechas();
      int busquedaBinaria(int size, Registro fecha_completa);
      void buscarRegistros(int inicial, int final);
      
      //Método que escribe el nuevo archivo
      void nuevoArchivo();
  };

#endif
