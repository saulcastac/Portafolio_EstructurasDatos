#include "Registro.h" 

Registro::Registro(){
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = "";
  error = "";
}

Registro::Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _error, dateTime _date){
  mes = _mes;
  dia = _dia;
  hora = _horas;
  minuto = _minutos;
  segundo = _segundos;
  ip = _ip;
  error = _error;
  date = _date;
}

dateTime Registro::getDate() {
  return date;
}

std::string Registro::getTexto() {
  return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + error;
}

bool Registro::operator==(const Registro &other) {
  return this->date == other.date;
}

bool Registro::operator!=(const Registro &other) {
  return this->date != other.date;
}

bool Registro::operator>(const Registro &other) {
  return this->date > other.date;
}

bool Registro::operator<(const Registro &other) {
  return this->date < other.date;
}

bool Registro::operator<=(const Registro &other) {
  return this->date < other.date;
}

bool Registro::operator>=(const Registro &other) {
  return this->date < other.date;
}