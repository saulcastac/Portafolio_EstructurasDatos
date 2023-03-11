#ifndef _DATETIME_H
#define _DATETIME_H

#include <ctime>
#include <iostream>
#include <vector>

class dateTime {
  private:
    // Variables necesarias
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;

  public:
    // Constructores
    dateTime();
    dateTime(std::string, int, int, int, int);

    // Metodos
    time_t getDate();
    
    // Sobrecarga de ooeradores
    bool operator ==(const dateTime&);
    bool operator !=(const dateTime&);
    bool operator >(const dateTime&);
    bool operator <(const dateTime&);
    bool operator >=(const dateTime&);
    bool operator <=(const dateTime&);
  
};

#endif