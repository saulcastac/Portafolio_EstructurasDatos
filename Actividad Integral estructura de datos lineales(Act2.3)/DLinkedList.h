#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_
  
  #include<iostream>
  #include <stdexcept>
  #include "DLLNode.h"

  template <class T>
  class DLinkedList {
      private:
        DLLNode<T> *head;
        DLLNode<T> *tail;
        int numElements;
        DLLNode<T> *partition(DLLNode<T> *l, DLLNode<T> *h);
        void swap (T &a, T &b); 
        void _quickSort(DLLNode<T> *l, DLLNode<T> *h);
        void Iterative_quickSort(DLLNode<T> *l, DLLNode<T> *h);

      public:
        DLinkedList();
        ~DLinkedList();
        int getNumElements();
        void printList();
        void printLastNode();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);

        void quickSort();  
        
};

  template<class T>
  DLinkedList<T>::DLinkedList() {
      std::cout << "--->Creando una lista vacia" << std::endl;
      head = nullptr;
      tail = nullptr;
      numElements = 0;
  }

  template<class T>
  DLinkedList<T>::~DLinkedList() {
      std::cout << "--->Liberando memoria de la lista ligada" << std::endl;
    DLLNode<T> *p, *q;
    p = head;
    while (p != nullptr) {
      q = p->next;
      delete p;
      p = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
  }

  template<class T>
  int DLinkedList<T>::getNumElements() {
    return numElements;
  }

  template<class T>
  void DLinkedList<T>::printList() {
    DLLNode<T> *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DLinkedList<T>::printLastNode() {
    std::cout << tail->data << std::endl;
  }

  template<class T>
  void DLinkedList<T>::addFirst(T value) {
    DLLNode<T> *newDLLNode = new DLLNode<T>(value);
    // Si la lista está vacia
    if (head == nullptr && tail == nullptr) {
      head = newDLLNode;
      tail = newDLLNode;
    }
    else {
      newDLLNode->next = head;
      head->prev = newDLLNode;
      head = newDLLNode;
    }
    numElements++;
  }

  template<class T>
  void DLinkedList<T>::addLast(T value) {
    if (head == nullptr && tail == nullptr) {
      addFirst(value);
    }
    else {
      DLLNode<T> *newDLLNode = new DLLNode<T>(value);
      tail->next = newDLLNode;
      newDLLNode->prev = tail; 
      tail = newDLLNode;
      numElements++;
    }
  }

  template<class T>
  bool DLinkedList<T>::deleteData(T value) {
    // Si la lista esta vacia 
    if (head == nullptr && tail == nullptr) {
      return false;
    }
    else {
      DLLNode<T> *p, *q;
      p = head;
      q = nullptr;
      // buscar value en la lista
      while (p != nullptr && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == nullptr)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == nullptr) {
        head = p->next;
        if (head != nullptr)
          head->prev = nullptr;
      }
      else if (p->next == nullptr) { 
        // Si debe borrarse el último elemento
        q->next = nullptr;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      throw std::out_of_range("Indice fuera de rango");
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      DLLNode<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != nullptr && head->next == nullptr) {
        head = tail = nullptr;  
      }
      else {
        head = p->next;
        head->prev = nullptr;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { // Si la lista contiene mas de un nodo
      DLLNode<T> *p = head, *q = nullptr;
      int index = 0;
      // Se busca el indice del elemento a borrar
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == nullptr) {
        q->next = nullptr;
        tail = q;
      }
      else { // Cualquier otro elemento en medio de la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  T DLinkedList<T>::getData(int position) {
    T tmp = {};
    if (position < 0 || position > numElements) {
      throw std::out_of_range("Indice fuera de rango");
    }
    else {
      if (position == 0)
        return head->data;
      DLLNode<T> *p = head;
      int index = 0;
      while (p != nullptr) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return tmp;
    }
  }

template<class T>
void DLinkedList<T>::swap(T &a, T &b){ 
  T t = a; a = b; b = t; 
};

template<class T>
DLLNode<T> * DLinkedList<T>::partition(DLLNode<T> *l, DLLNode<T> *h){
    // set pivot as h element
    T x = h->data;
  
    // similar to i = l-1 for array implementation
    DLLNode<T> *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (DLLNode<T> *j = l; j != h; j = j->next){
        if (j->data <= x){
            // Similar to i++ for array
            i = (i == nullptr)? l : i->next;
            swap((i->data), (j->data));
        }
    }
    i = (i == nullptr)? l : i->next; // Similar to i++
    swap((i->data), (h->data));
    return i;
}

//geek for geeks
template <class T>
void DLinkedList<T>::_quickSort(DLLNode<T> *l, DLLNode<T> *h){
    if (h != NULL && l != h && l != h->next){
       DLLNode<T> * p = partition(l, h);//Nos regresa un tipo registro, lo cambianos de DLLNode
      _quickSort(l, p->prev);
      _quickSort(p->next, h);
    }
}

//geek for geeks
template <class T>
void DLinkedList<T>::Iterative_quickSort(DLLNode<T> *l, DLLNode<T> *h){
  
  //Creamos un stack
  DLLNode<T>* stack[h - l + 1];
  //Inicializamos el top del stack
  int top = -1;
  // push initial values of l and h to stack
  stack[++top] = l;
  stack[++top] = h;
  // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
        DLLNode<T> * p = partition(l, h);
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

template <class T>
void DLinkedList<T>::quickSort(){
    // Call the recursive QuickSort
    Iterative_quickSort(head, tail);//Este estamos probando con el iterative quickSort
}


#endif // _DLINKEDLIST_H_