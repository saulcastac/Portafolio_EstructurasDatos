#include "Bitacora.h"



// Constructor de Bitacora
Bitacora::Bitacora(){

}

// ------------- PUNTO 1 ------------- //

// Metodo para leer el archivo (Punto 1)
void Bitacora::leerArchivo(std::string Archivo_a_leer){
    //Lee el archivo 
    std::ifstream file(Archivo_a_leer);
    // Excepcion para abrir el archivo
    if (!file.good()) {
      file.close();
      throw std::invalid_argument("File not found");
    }
    // Si si abre entonces...
    else {
      // Mientras el archivo no esté vacio
      while (!file.eof()) {
        // validar linea vacia
        std::getline(file, month, ' ');
        if (!month.empty()) {
          std::getline(file, day, ' ');
          std::getline(file, hours, ':');
          std::getline(file, minutes, ':');
          std::getline(file, seconds, ' ');
          std::getline(file, ipAdd, ':');
          std::getline(file, port, ' ');
          std::getline(file, error);
          // Crear objeto de tipo Registro
          Registro tmpRegistro(month, day, hours, minutes, seconds, ipAdd, port, error);
          // Agregar al vector de regisrros
          listaRegistros.push_back(tmpRegistro);
        }
      }
      // Cerrar archivo 
      file.close();
      // Llamar al metodo para ordenar
      //std::cout << "Size: " << listaRegistros.size() << std::endl;
      heapSort(listaRegistros.size());
    }
}

// ------------- PUNTO 2 ------------- //

// Función que ordena la lista con Heap Sort
// Código adaptado de:
// https://www.geeksforgeeks.org/heap-sort/

void Bitacora::heapSort(int n) {
  // Construye el heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(n, i); 
  // Toma uno por uno cada elemento del heap
  for (int i = n - 1; i > 0; i--) {   
    // Mueve el elemento a la rama adecuada
    std::swap(listaRegistros[0], listaRegistros[i]);
    // Llama al metodo heapify para ordener de nuevo
    heapify(i, 0);
  }
}

// Metodo complementario a heap Sort
// Código adaptado de:
// https://www.geeksforgeeks.org/heap-sort/

void Bitacora::heapify(int n, int i) {
  // Initialize largest as root
  int largest = i;
  // left = 2*i + 1
  int l = 2 * i + 1; 
  // right = 2*i + 2
  int r = 2 * i + 2;
  // If left child is larger than root
    if (l < n && listaRegistros[l] > listaRegistros[largest])
        largest = l;
    // If right child is larger than largest
    // so far
    if (r < n && listaRegistros[r] > listaRegistros[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        std::swap(listaRegistros[i], listaRegistros[largest]);
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}

// ------------- PUNTO 2 ------------- //

// Metodo para generar un nuevo archivo con los datos ordenados
void Bitacora::nuevoArchivo(){
  // Crea un objeto para el archivo vacio
  std::ofstream file;
  // Abre el archivo creado
  file.open("bitacora_ordenada.txt");
  // Barre el vector de datos
  for (int i = 0; i < getSize(); i++){
    // Llena el archivo con los elementos del vector
    file<<this->listaRegistros[i].getAll()<<"\n";
  }
  // Cierra el archivo
  file.close();
}

// ------------- PUNTO 3 ------------- //

void Bitacora::contadorAccesos(){
  // Inicializamos variables
  iteraciones = 0;
  
  // Lista de tipo Priority heap
  PriorityHeap<Toto> lista_repetidos(listaRegistros.size());
  

  // Cicilo para barrer toda la lista de registros
  while(iteraciones != listaRegistros.size()){
    // Reincio de variables cada que el registro cambia
    repetidos = 1;
    acum = 1;
    
    // Ciclo para comparar todos los registros que son iguales
    while(listaRegistros[iteraciones] == listaRegistros[iteraciones + acum]){
      // Aumento de variables como contadores
      repetidos++;
      acum++;      
    }
    // Generar objeto de tipo Toto con repetidos, ip en texto y ip en numero
    Toto tmpToto (repetidos, listaRegistros[iteraciones].getIP_texto(), listaRegistros[iteraciones].getIP());
        
    // Llenando la lista de repetidos
    lista_repetidos.push(tmpToto);

    
    // Condición para que solo se use uno de los registros que se repite
    if(listaRegistros[iteraciones] != listaRegistros[iteraciones + acum]){
      // Cambio de posición de la iteración para evitar ciclar la función
      iteraciones = iteraciones + acum - 1;
    }
    // Aumento de la iteración
    iteraciones ++;
  }
  // Imprime los primeros 5 valores del BST
  lista_repetidos.printPriorityHeap(5);
  
  // ------------- PUNTO 4 ------------- //
  
  // Llama al metodo que genera el archivo con los repetidos
  lista_repetidos.imprime();
 
}

// ------------- MÉTODOS COMPLEMENTARIOS ------------- //

// Metodo para obtener el tamaño de la lista
int Bitacora::getSize(){
    return listaRegistros.size();
}

// Imprimir la lista completa
void Bitacora::print() {
  for (int i=0; i < listaRegistros.size(); i++) {
    std::cout << listaRegistros[i].getAll() << std::endl;
  }
}