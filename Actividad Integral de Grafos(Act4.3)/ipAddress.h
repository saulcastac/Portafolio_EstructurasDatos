#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <cmath>
#include <iostream>
#include <vector>

class ipAddress {
    private:
      std::string ipString;
      std::string ipPort;
      int ipIndex;
      long int ipValue;
      int degree;

    public:
      ipAddress();
      ipAddress(std::string _ip, std::string _port, int idx);
      std::string getIp();
      std::string getIpPort();
      unsigned int getIpValue();
      int getIpIndex();
      void setDegree(int g);
      void addToDegree();
      int getDegree();

      bool operator ==(const ipAddress&);
      bool operator !=(const ipAddress&);
      bool operator >(const ipAddress&);
      bool operator >=(const ipAddress&);
      bool operator <(const ipAddress&);
      bool operator <=(const ipAddress&);
      /* incorrecto 
      bool operator ==(ipAddress);
      bool operator !=(ipAddress);
      bool operator >(ipAddress);
      bool operator <(ipAddress);
      bool operator >=(ipAddress);
      bool operator <=(ipAddress);
      */
};


#endif
