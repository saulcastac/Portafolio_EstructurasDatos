#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Bitacora.h"

int main(){
    Bitacora Nuevo_registro;//Creamos el objeto de tipo bitacora
    Nuevo_registro.leerArchivo("bitacora.txt");//Mandamos leer nuestra bitacora con el método leerArchivo
    Nuevo_registro.ordenaLista();//Mandamos ordenar nuestra bitacora con el método ordenLista
    Nuevo_registro.nuevoArchivo();//Se crea un nuevo archivo con la lista de registros ordenada
    
    Nuevo_registro.busquedaFechas();//Se utiliza el método busquedaFechas para buscar fechas en un parámetro dado

    return 0;
}