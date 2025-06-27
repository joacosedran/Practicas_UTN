#include <iostream>
using namespace std;

// Mostrar y Ordenar: plantilla de un solo tipo
template <typename T>
void MostrarArray(T *v, int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n\n";
}

template <typename T>
void OrdenarArray(T *v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                T aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

template <typename T1, typename T2>
void ApareoArrays(T1 *v1, int v1size, T2 *v2, int v2size)
{
    using R = float;
    const int totalSize = v1size + v2size;
    R v3[totalSize];
    int k = 0;

    // Copiar todos los elementos de v1
    for (int i = 0; i < v1size; ++i)
        v3[k++] = v1[i];

    // Copiar todos los elementos de v2
    for (int j = 0; j < v2size; ++j)
        v3[k++] = v2[j];

    cout << "\nVectores concatenados";
    MostrarArray(v3, totalSize);
}

int main()
{
    int v1size = 6;
    int v2size = 5;

    // Cambia el tipo de dato
    using T1 = float;
    using T2 = int;

    T1 v1[v1size] = {12.25, 14.20, 150, 2.5, 32, 12};
    T2 v2[v2size] = {42, 14, 72, 53, 10};
    int opcion;

    bool v1_ordenado = false;
    bool v2_ordenado = false;

    // Punteros a funcion
    void (*Mostrar1)(T1 *, int) = &MostrarArray<T1>;
    void (*Mostrar2)(T2 *, int) = &MostrarArray<T2>;
    void (*Ordenar1)(T1 *, int) = &OrdenarArray<T1>;
    void (*Ordenar2)(T2 *, int) = &OrdenarArray<T2>;
    void (*Apareo)(T1 *, int, T2 *, int) = &ApareoArrays<T1, T2>;

    do
    {
        cout << "1. Mostrar v1\n";
        cout << "2. Mostrar v2\n";
        cout << "3. Ordenar v1\n";
        cout << "4. Ordenar v2\n";
        cout << "5. Aparear v1 y v2\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Mostrar1(v1, v1size);
            break;
        case 2:
            Mostrar2(v2, v2size);
            break;
        case 3:
            cout << "\nv1 ordenado";
            Ordenar1(v1, v1size);
            v1_ordenado = true;
            Mostrar1(v1, v1size);
            break;
        case 4:
            cout << "\nv2 ordenado";
            Ordenar2(v2, v2size);
            v2_ordenado = true;
            Mostrar2(v2, v2size);
            break;
        case 5:
            if (!v1_ordenado || !v2_ordenado)
            {
                cout << "\nPrimero ambos vectores deben estar ordenados.\n";
                if (!v1_ordenado)
                {
                    cout << "Ordenando v1";
                    Ordenar1(v1, v1size);
                    v1_ordenado = true;
                    Mostrar1(v1, v1size);
                }
                if (!v2_ordenado)
                {
                    cout << "Ordenando v2";
                    Ordenar2(v2, v2size);
                    v2_ordenado = true;
                    Mostrar2(v2, v2size);
                }
            }
            Apareo(v1, v1size, v2, v2size);
            break;
        case 6:
            cout << "Saliendo...\n";
            return 0;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (true);
    return 0;
}
