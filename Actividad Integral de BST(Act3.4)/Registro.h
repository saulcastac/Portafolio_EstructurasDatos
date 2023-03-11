#ifndef _REGISTRO_H
#define _REGISTRO_H

  #include <string>
  #include <cmath>
  #include "dateTime.h"
  
  class Registro {
      private:
        // Inicializamos todas las variables y vectores necesarios
        std::string mes, dia, hora, minutos, segundos, ip, puerto, RazonDeFalla, splitted;
        int partA, partB, partC, partD, posInit, posFound;
        unsigned int ipValue;

        // Vectores necesarios
        std::vector<std::string> results; 
        std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
        
        // Struct que contiene todos los datos de la fecha-hora
        struct tm dateStruct;
        
        // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
        time_t dateTime;
      
      public:
        // Constructores
        Registro();
        Registro(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
        
        // Metodos para obtener Información de la lista
        std::string getAll();
        unsigned int getIP();
        std::string getIP_texto();
        
        // Metodos para comparar registros por medio de sobrecarga de operadores
        bool operator ==(const Registro&);
        bool operator !=(const Registro&);
        bool operator >(const Registro&);
        bool operator <(const Registro&);
        bool operator >=(const Registro&);
        bool operator <=(const Registro&);
  };


#endif

