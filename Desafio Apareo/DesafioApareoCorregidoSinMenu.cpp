#include <iostream>
using namespace std;

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
    const int totalSize = v1size + v2size;
    float v3[totalSize];
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

    float v1[v1size] = {12.25, 14.20, 150, 2.5, 32, 12};
    int v2[v2size] = {42, 14, 72, 53, 10};

    // Punteros a funcion
    void (*Mostrar1)(float *, int) = &MostrarArray<float>;
    void (*Mostrar2)(int *, int) = &MostrarArray<int>;
    void (*Ordenar1)(float *, int) = &OrdenarArray<float>;
    void (*Ordenar2)(int *, int) = &OrdenarArray<int>;
    void (*Apareo)(float *, int, int *, int) = &ApareoArrays<float, int>;

    Mostrar1(v1, v1size);
    Mostrar2(v2, v2size);

    Ordenar1(v1, v1size);
    Ordenar2(v2, v2size);

    Mostrar1(v1, v1size);
    Mostrar2(v2, v2size);

    Apareo(v1, v1size, v2, v2size);

    return 0;
}