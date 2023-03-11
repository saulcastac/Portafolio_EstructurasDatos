
#include "dateTime.h"

// Constructor
dateTime::dateTime() {

}

// Constructor para convertir los datos a una fecha en segundos
dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {

  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;

  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
}

// Método para obeter la fecha
time_t dateTime::getDate() {
  std::cout<<date;
  return date;
}

// Métodos para comprar fechas contra fechas por medio de sobrecarga de operadores
bool dateTime::operator==(const dateTime &other) {
  return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
  return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
  return this->date < other.date;
}

bool dateTime::operator<=(const dateTime &other) {
  return this->date < other.date;
}

bool dateTime::operator>=(const dateTime &other) {
  return this->date < other.date;
}