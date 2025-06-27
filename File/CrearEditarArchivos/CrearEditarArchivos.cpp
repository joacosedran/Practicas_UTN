/*
En este codigo se crea un archivo binario
llamado "datos.bin", si existe un anterior
este no se elimina, sino que se modifica.
*/
#include <iostream>
using namespace std;

struct Registro
{
    int id;
    char nombre[50];
};

int main()
{
    int i;
    Registro registro1;
    FILE *archivo;

    // Intentar abrir el archivo en modo lectura/escritura binaria
    archivo = fopen("datos.bin", "rb+");
    if (archivo == NULL)
    {
        // Si no existe, crearlo
        archivo = fopen("datos.bin", "wb+");
        if (archivo == NULL)
        {
            cout << "No se pudo abrir o crear el archivo." << endl;
            return 1;
        }
    }

    // Mover el puntero al final para agregar registros
    fseek(archivo, 0, SEEK_END);

    // Agregar nuevos registros
    for (i = 0; i < 4; i++)
    {
        cout << "Ingrese ID:  ";
        cin >> registro1.id;
        cout << "Ingrese Nombre:  ";
        cin >> registro1.nombre;

        fwrite(&registro1, sizeof(Registro), 1, archivo);
    }

    // Mostrar todos los registros
    fflush(archivo);
    fseek(archivo, 0, SEEK_SET);

    cout << "\nRegistros en el archivo:" << endl;
    while (fread(&registro1, sizeof(Registro), 1, archivo) == 1)
    {
        cout << "ID: " << registro1.id << ", Nombre: " << registro1.nombre << endl;
    }

    fclose(archivo);

    return 0;
}