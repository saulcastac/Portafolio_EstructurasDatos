#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Registro.h"

template <class T>
class leerArchivo{
    public:
        // Metodos
        void abrirArchivo(std::vector<T *>);

    private:
        std::string _mes, _dia, _hora, _minutos, _segundos, _dirIP, _error;
        std::string mes, dirIP, error, line, dato, errAcceso;
        int dia, horas, minutos, segundos;
        std::ifstream archivo;
        std::vector<std::string> vecAux;
        
};

template<class T>
void leerArchivo<T>::abrirArchivo(std::vector<T *>vecSalida){
     try{
        archivo.open("test01.txt");
        std::cout << " Se abrio con exito el archivo " << std::endl;    
        if (archivo.is_open()) {
            while (getline(archivo, line)) {
                std::stringstream sstr(line);
                while (getline(sstr, dato, ' ')) {
                vecAux.push_back(dato); // se agaraga el vector cada renglón
            }

            // Concatemanos el string correspondeinte al fallo o error
            errAcceso = vecAux[4];
            int tamanio = vecAux.size();
            for (int i = 5; i < tamanio; i++) {
            errAcceso += (" " + vecAux[5]);
            vecAux[4] = errAcceso;
            vecAux.erase(vecAux.begin() + 5);
            }

            // Hacemos una segunda división para obtener los números enteros de horas,
            // minutos y segundos
            std::string horario = vecAux[2];
            std::stringstream lineahora(horario);
            std::vector<std::string> time;
            std::string hora = "";
            while (getline(lineahora, hora, ':')) {
            time.push_back(hora);
            }

            // Generamos de forma dinámica los objetos tipo Acceso con los datos
            // obtenidos del archivo
            mes = vecAux[0];
            dia = stoi(vecAux[1]);
            horas = stoi(time[0]);
            minutos = stoi(time[1]);
            segundos = stoi(time[2]);
            dirIP = vecAux[3];
            error = vecAux[4];  

            vecSalida.push_back(new Registro(mes, dia, horas, minutos, segundos, dirIP, error));    
            }
        archivo.close();
        } 
        else {
            std::cout << "Error de lectura de archivo" << std::endl;
        }
    }
    catch(...){
    std::cout << " Error al leer el archivo " << std::endl;
    }
}


#endif /*LEERARCHIVO_H*/