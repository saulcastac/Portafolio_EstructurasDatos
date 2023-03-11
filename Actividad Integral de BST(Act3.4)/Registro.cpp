
#include "Registro.h" 

// Constructor que inicia las variables vacias
Registro::Registro() {
  mes = "";
  dia = "";
  hora = "";
  minutos = "";
  segundos = "";
  ip = "";
  puerto = "";
  RazonDeFalla = "";
}

// Constructor de la clase Registro
Registro::Registro(std::string MES, std::string DIA, std::string HORA, std::string MINUTOS, std::string SEGUNDOS, std::string IP, std::string PUERTO, std::string RAZON_DE_FALLA) {
  // Iniciamos las variables con los datos que vienen de fuera
  mes = MES;
  dia = DIA;
  hora = HORA;
  minutos = MINUTOS;
  segundos = SEGUNDOS;
  ip = IP;
  puerto = PUERTO;
  RazonDeFalla = RAZON_DE_FALLA;

  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = std::stoi(segundos);
  dateStruct.tm_min = std::stoi(minutos);
  dateStruct.tm_hour = std::stoi(hora);
  dateStruct.tm_mday = std::stoi(dia);

  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2022 - 1900;  // Asumimos el año 2022
  // Obtener el Unix timestamp a partir del struct tm anterior 
  // Numero de segundos desde el 1 de enero de 1970
  dateTime = mktime(&dateStruct);

  // Convertir IP
  // Código adaptado de : 
  // https://es.stackoverflow.com/questions/64062/dividir-string-c-split
  // Partimos la IP en 4 secciones  
  posInit = 0; posFound = 0;
  while(posFound >= 0) {
    posFound = ip.find(".", posInit);
    splitted = ip.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  // Transformamos a enteros los valores partidos
  partA = std::stoi(results[0]);
  partB = std::stoi(results[1]);
  partC = std::stoi(results[2]);
  partD = std::stoi(results[3]);

  // Convertimos la IP a un número decimal entero 
  ipValue = partA*(pow(256,3)) + partB*(pow(256,2)) + partC*(pow(256,1)) + partD;
}

// Metodo para obtener la Ip como decimal entero
unsigned int Registro::getIP() {
  return ipValue;
}

std::string Registro::getIP_texto() {
  return ip;
}

// Metodo para obtener los datos como tipo Registro
std::string Registro::getAll() {
  return mes +" " + dia + " " + hora + ":" + minutos + ":" + segundos + " " + ip + ":" + puerto + " " + RazonDeFalla + " ";
}

// Metodos para hacer comparaciones entre Registros por medio de sobrecarga de operadores
bool Registro::operator==(const Registro &other) {
  return this->ipValue == other.ipValue;
}

bool Registro::operator!=(const Registro &other) {
  return this->ipValue != other.ipValue;
}

bool Registro::operator>(const Registro &other) {
  return this->ipValue > other.ipValue;
}

bool Registro::operator<(const Registro &other) {
  return this->ipValue < other.ipValue;
}

bool Registro::operator<=(const Registro &other) {
  return this->ipValue < other.ipValue;
}

bool Registro::operator>=(const Registro &other) {
  return this->ipValue < other.ipValue;
}