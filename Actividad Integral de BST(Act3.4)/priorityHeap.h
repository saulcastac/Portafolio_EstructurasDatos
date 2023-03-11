#ifndef __PRIORITYHEAP_H_
#define __PRIORITYHEAP_H_

  #include <vector>
  #include <iostream>
  #include <stdexcept>
  #include <fstream>


  template<class T>
  class PriorityHeap {
    private:
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size; 
      // Metodos para moverte por el heap
      int parent(int i);
      int left(int i);
      int right(int i);

    public:
      // COnstructores
      PriorityHeap(int capacity);
      ~PriorityHeap();
      // Metodos
      int getCapacity();
      void printPriorityHeap(int);
      bool isEmpty();
      void push(T key);
      T top();
      void pop();
      int getSize();
      void imprime();
};

  template <class T> 
  PriorityHeap<T>::PriorityHeap(int capacity) {
      std::cout << " --->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  PriorityHeap<T>::~PriorityHeap() {
      std::cout << " --->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }
  
  template <class T> 
  bool PriorityHeap<T>::isEmpty() {
      if(size <= 0){
        return true;
      }
      else{
        return false;
      }
  }

  template <class T> 
  int PriorityHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T> 
  void PriorityHeap<T>::printPriorityHeap(int tope) {
    for (int i=0; i < tope; i++){
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }

  template <class T> 
  int PriorityHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int PriorityHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int PriorityHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T> 
  void PriorityHeap<T>::push(T key) {
      if (size == maxSize) {
      throw std::out_of_range("Overflow: no se puede insertar la llave: ");
      }
      // Insertamos la nueva llave al final del vector
      int i = size;
      int check = 0;
      data[i] = key;
      size++;
      // Reparar las propiedades del max heap si son violadas
      while (i != 0 && data[parent(i)] < data[i]) {
          std::swap(data[i], data[parent(i)]);
          i = parent(i);
      }
  }
  
  template <class T> 
  T PriorityHeap<T>::top() {
      if(data[0] != 0){
        return data[0];
      }
      else{
          return 0;
      }
  }

  template <class T> 
  void PriorityHeap<T>::pop() {
      int tamanio = size;
      if(size != 0){
        for(int i = 0; i < tamanio; i++ ){
            std::swap(data[i], data[i+1]);
        }
        size--;
      }
      else{
          std::cout << " No hay datos que eliminar " << std::endl;
      }
     
  }

  template <class T> 
  int PriorityHeap<T>::getSize() {
    return size;
  }

template <class T>
void PriorityHeap<T>::imprime(){
  
  std::ofstream file;
  // Abre el archivo creado
  file.open("ips_con_mayor_acceso.txt");
  // Barre el vector de datos
  for (int i = 0; i < getSize(); i++){
    // Llena el archivo con los elementos del vector
    file<<this-> data[i] <<"\n";
  }
}

#endif // __PRIORITYHEAP_H_