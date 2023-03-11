#ifndef _TOTO_H
#define _TOTO_H

#include <string>
#include <vector>
#include <ostream>


class Toto {
  private:
    // Variables Iniciales
    std::string IP_text, cont, IP_num;
    int contaCompara;


  public:
    // Constructores
    Toto();
    Toto(int contador, std::string ip_text, unsigned int ip_num);

    // Metodo para imprimir Toto
    std::string getText();

    // Metodos para comparar Toto por medio de sobrecarga de operadores
    bool operator ==(const Toto&);
    bool operator !=(const Toto&);
    bool operator >(const Toto&);
    bool operator <(const Toto&);
    bool operator >=(const Toto&);
    bool operator <=(const Toto&);
    friend std::ostream& operator<<(std::ostream& os, const Toto& dt);

};



#endif // _TOTO_H