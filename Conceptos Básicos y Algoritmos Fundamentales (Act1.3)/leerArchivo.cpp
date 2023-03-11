#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "leerArchivo.h"
#include "Registro.h"

// Constructor
leerArchivo::leerArchivo(){}

// Función para leer el archivo y ponerlo en un vector
void leerArchivo::lArchivo(vector<Registro *> global_vec) {
  ifstream archivo;
  archivo.open("bitacora.txt");
  if (archivo.is_open()) {
    string line;
    while (getline(archivo, line)) {
      stringstream sstr(line);
      string dato;
      vector<string> vecAux;
      while (getline(sstr, dato, ' ')) {
        vecAux.push_back(dato); // se agaraga el vector cada renglón
      }
      // Concatemanos el string correspondeinte al fallo o error
      string errAcceso = vecAux[4];
      int tamanio = vecAux.size();
      for (int i = 5; i < tamanio; i++) {
        errAcceso += (" " + vecAux[5]);
        vecAux[4] = errAcceso;
        vecAux.erase(vecAux.begin() + 5);
      }
      
      // Hacemos una segunda división para obtener los números enteros de horas,
      // minutos y segundos
      string horario = vecAux[2];
      stringstream lineahora(horario);
      vector<string> time;
      string hora = "";
      while (getline(lineahora, hora, ':')) {
        time.push_back(hora);
      }

      // Generamos de forma dinámica los objetos tipo Acceso con los datos
      // obtenidos del archivo
      string mes = vecAux[0];
      int dia = stoi(vecAux[1]);
      int horas = stoi(time[0]);
      int minutos = stoi(time[1]);
      int segundos = stoi(time[2]);
      string dirIP = vecAux[3];
      string error = vecAux[4];
      
      Registro *object;      
      global_vec.push_back(object);
      object -> Register(mes, dia, hora, minutos, segundos, dirIP, error);

    }
    archivo.close();
  } else {
    cout << "Error de lectura de archivo" << endl;
  }
}

// Punto 5. Función para escribir la lista ordenada
void escribeArchivo(vector<Registro *> global_vec) {
  ofstream archivo;
  string nombre = "bitacoraOrdenada.txt";
  archivo.open(nombre.c_str(), fstream::out);
  int tam = global_vec.size();
  for (int i = 0; i < tam; i++) {
    archivo << global_vec[i]->getMes() << " " << global_vec[i]->getDia() << " "
            << global_vec[i]->getHora() << ":" << global_vec[i]->getMinutos() << ":"
            << global_vec[i]->getSegundos() << " " << global_vec[i]->getDirIP() << " "
            << global_vec[i]->getError() << " " << endl;
  }
  archivo.close();
}

// Para el cambio de valores en el vector
void swapVec(vector<Registro *> global_vec, int i, int j) {
  Registro *paso = global_vec[i];
  global_vec[i] = global_vec[j];
  global_vec[j] = paso;
}

// Punto 2.
// Las siguientes funciones son de la implemntación del método Quick Sort
// Complejidada computacional O(n*log2(n)) en promedio
int particion(vector<Registro *> global_vec, int ini, int fin) {
  time_t pivote = global_vec[ini]->getFecha();
  int i = ini + 1;
  for (int j = ini; j <= fin; j++) {
    if (global_vec[j]->getFecha() < pivote) {
      swapVec(global_vec,i++, j);
    }
  }
  swapVec(global_vec, ini, i - 1);
  return i-1;
}

void quickSort(vector<Registro *> global_vec, int ini, int fin) {
  if (ini < fin) {
    int piv = particion(global_vec, ini, fin);
    quickSort(global_vec, ini, piv);
    quickSort(global_vec, piv + 1, fin);
  }
}

void quickSortO(vector<Registro *> global_vec) { 
  quickSort(global_vec, 0, global_vec.size() - 1); 
}

// Impalemntación de la búsqueda binaria
// Complejidad O(log2(n))
int busqBinaria(vector<Registro *> global_vec, time_t inf, time_t sup) {
  int min = 0;
  int max = global_vec.size() - 1;
  while (min <= max) {
    int avg = (min + max) / 2;
    time_t fecha = global_vec[avg]->getFecha();
    if (fecha >= inf && fecha <= sup) {
      return avg;
    } else if (fecha > sup) {
      max = avg - 1;
    } else {
      min = avg + 1;
    }
  }
  return -1;
}