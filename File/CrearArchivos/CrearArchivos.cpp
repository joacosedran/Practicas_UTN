/*
En este codigo cada vez que se ejecuta
se crea un archivo binario llamado "datos.bin",
pisando el archivo anterior si existe.
*/
#include <iostream>
using namespace std;

struct Registro {
    int id;
    char nombre[50];
};

int main() {
    int i;
    Registro registro1;
    FILE *archivo;                 // Declarar el puntero al archivo
    archivo = fopen("datos.bin", "wb+"); // Abrir el archivo en modo binario para escritura y lectura

    for(i = 0; i < 4; i++) {
        cout << "Ingrese ID:  ";
        cin >> registro1.id; // Leer el ID desde la entrada estándar
        cout << "Ingrese Nombre:  ";
        cin >> registro1.nombre; // Leer el nombre desde la entrada estándar

        // Escribir el registro en el archivo
        // (Direccion del registro, tamaño del registro, cantidad de registros a escribir, archivo)
        fwrite(&registro1, sizeof(Registro), 1, archivo); 
    }

    // Mostrar datos
    // (archivo, desplazamiento, desde que posición)
    fseek(archivo, 0, SEEK_SET); // Volver al inicio del archivo 

    while(!feof(archivo)) { // Mientras no se llegue al final del archivo (feof = end of file)
        fread(&registro1, sizeof(Registro), 1, archivo); // Leer un registro del archivo
        cout << "ID: " << registro1.id << ", Nombre: " << registro1.nombre << endl; // Mostrar el registro leído
    }

    fclose(archivo); // Cerrar el archivo

    return 0;
}