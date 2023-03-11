#ifndef _REGISTRO_H
#define _REGISTRO_H

  #include <string>
  #include "dateTime.h"
  
  class Registro {
      private:
        dateTime date;
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        std::string ip;
        std::string error;

      
      public:
        Registro();
        Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _error, dateTime _date);
        std::string getTexto();
        dateTime getDate();
        bool operator ==(const Registro&);
        bool operator !=(const Registro&);
        bool operator >(const Registro&);
        bool operator <(const Registro&);
        bool operator >=(const Registro&);
        bool operator <=(const Registro&);
  };


#endif

