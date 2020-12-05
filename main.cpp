#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void generadorNumerosAleatorios(int * V, int n);

void leer(int * V, int n);

int particion(int * V, int l_inferior, int l_superior);

void quickSort(int * V, int l_inferior, int l_superior);

void intercambiar(int * V, int i, int j);

bool esta_ordenado(const int * V, int n);

using namespace std;

int main()
{
    const int n = 30000;
    int V[n];

    generadorNumerosAleatorios(V, n);

    quickSort(V, 0, n);
    clock_t inicio = clock();
    quickSort(V, 0, n);
    clock_t fin = clock();

    clock_t tiempo = fin - inicio;
    double tiempoSegundos = tiempo / (double) CLOCKS_PER_SEC;
    cout << "Numeros ordenados: " << n << endl;
    cout << "Tiempo en segundos: " << tiempoSegundos << endl;
    cout << "Esta Ordenado? : " << esta_ordenado(V, n) << endl;
    return 0;


}

void generadorNumerosAleatorios(int *V, int n) {
    unsigned t = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine f(t);

    uniform_int_distribution<int> distUniforme(-500000, 500000);

    for (int i = 0; i < n; i++)
        V[i] = distUniforme(f);

}

void leer(int *V, int n) {

    cout << "\nArreglo: " << endl;

    for (int i = 0; i < n; i++)
        cout << V[i] << " ";

    cout << endl;
}

int particion(int * V, int l_inferior, int l_superior)
{
    int pivote = V[l_inferior];
    int i = l_inferior;

    for (int j = l_inferior + 1; j < l_superior; j++)
    {
        if (V[j] < pivote)
        {
            i++;
            intercambiar(V, i, j);
        }
    }
    intercambiar(V, l_inferior, i);

    return i;
}

void quickSort(int * V, int l_inferior, int l_superior)
{
    if (l_inferior < l_superior)
    {
        int posicion_pivote = particion(V, l_inferior, l_superior);

        quickSort(V, l_inferior, posicion_pivote);
        quickSort(V, posicion_pivote + 1, l_superior);
    }
}

void intercambiar(int * V, int i, int j)
{
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}

bool esta_ordenado(const int * V, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (V[i] > V[i + 1])
            return false;
    }
    return true;
}