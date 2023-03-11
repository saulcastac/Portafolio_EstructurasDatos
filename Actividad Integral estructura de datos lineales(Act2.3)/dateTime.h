#ifndef _DATETIME_H
#define _DATETIME_H

#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

class dateTime {
  public:
    dateTime();
    dateTime(std::string mes, int dia, int horas, int minutos, int segundos);
    time_t getDate();
    bool operator ==(const dateTime&);
    bool operator !=(const dateTime&);
    bool operator >(const dateTime&);
    bool operator <(const dateTime&);
    bool operator >=(const dateTime&);
    bool operator <=(const dateTime&);
  
  private:
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
};

#endif