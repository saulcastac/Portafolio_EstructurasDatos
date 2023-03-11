#include "Toto.h"

Toto::Toto(){

}

Toto::Toto(int contador, std::string ip_text, unsigned int ip_num){
  IP_text = ip_text;
  IP_num = std::to_string(ip_num);
  cont = std::to_string(contador);
  contaCompara = contador;
}
  std::string Toto::getText(){
  return IP_text + " -> " + cont + " ";
}

// Metodos para hacer comparaciones entre Registros por medio de sobrecarga de operadores
bool Toto::operator==(const Toto &other) {
  return this->contaCompara == other.contaCompara;
}

bool Toto::operator!=(const Toto &other) {
  return this->contaCompara != other.contaCompara;
}

bool Toto::operator>(const Toto &other) {
  return this->contaCompara > other.contaCompara;
}

bool Toto::operator<(const Toto &other) {
  return this->contaCompara < other.contaCompara;
}

bool Toto::operator<=(const Toto &other) {
  return this->contaCompara < other.contaCompara;
}

bool Toto::operator>=(const Toto &other) {
  return this->contaCompara < other.contaCompara;
}

//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
std::ostream& operator<<(std::ostream& os, const Toto& tmpToto) {
  os << tmpToto.IP_text << " -> " << tmpToto.cont;
  return os;
}

