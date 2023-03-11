#ifndef _IP_HASH_H_
#define _IP_HASH_H_

#include <iostream>

class ipHash{
  private:
    std::string ipText, aristasaliendo, aristaLlegando;

  public:
    ipHash();
    ipHash(std::string, int, int);
    std::string printIpHash();

};



#endif //_IP_HASH_H_