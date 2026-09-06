#include <iostream>
using namespace std;
void bubbleSort(int numeros[], int n) {

    int i, j, aux;

    for(i = 0; i < n; i++) {

        for(j = 0; j < n - 1; j++) {

            if(numeros[j] > numeros[j + 1]) {

                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}
void insertionSort(int numeros[], int n) {

    int i, pos, aux;

    for(i = 0; i < n; i++) {

        pos = i;
        aux = numeros[i];

        while(pos > 0 && numeros[pos - 1] > aux) {

            numeros[pos] = numeros[pos - 1];
            pos--;
        }

        numeros[pos] = aux;
    }
}
void selectionSort(int numeros[], int n) {

    int i, j, min, aux;

    for(i = 0; i < n; i++) {

        min = i;

        for(j = i + 1; j < n; j++) {

            if(numeros[j] < numeros[min]) {
                min = j;
            }
        }

        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
    }
}
void merge(int numeros[], int inicio, int medio, int fin) {

    int aux[100];
    int i = inicio;
    int j = medio + 1;
    int k = 0;

    while(i <= medio && j <= fin) {

        if(numeros[i] < numeros[j]) {
            aux[k] = numeros[i];
            i++;
        }
        else {
            aux[k] = numeros[j];
            j++;
        }

        k++;
    }

    while(i <= medio) {
        aux[k] = numeros[i];
        i++;
        k++;
    }

    while(j <= fin) {
        aux[k] = numeros[j];
        j++;
        k++;
    }

    for(i = inicio, k = 0; i <= fin; i++, k++) {
        numeros[i] = aux[k];
    }
}

void mergeSort(int numeros[], int inicio, int fin) {

    if(inicio < fin) {

        int medio = (inicio + fin) / 2;

        mergeSort(numeros, inicio, medio);
        mergeSort(numeros, medio + 1, fin);

        merge(numeros, inicio, medio, fin);
    }
}
void quickSort(int numeros[], int inicio, int fin) {

    int i = inicio;
    int j = fin;
    int pivote = numeros[(inicio + fin) / 2];
    int aux;

    while(i <= j) {

        while(numeros[i] < pivote) {
            i++;
        }

        while(numeros[j] > pivote) {
            j--;
        }

        if(i <= j) {

            aux = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = aux;

            i++;
            j--;
        }
    }

    if(inicio < j) {
        quickSort(numeros, inicio, j);
    }

    if(i < fin) {
        quickSort(numeros, i, fin);
    }
}
void heapSort(int numeros[], int n) {

    int i, j, hijo, aux;

    // Crear Heap
    for(i = n / 2 - 1; i >= 0; i--) {

        j = i;

        while(2 * j + 1 < n) {

            hijo = 2 * j + 1;

            if(hijo + 1 < n && numeros[hijo + 1] > numeros[hijo]) {
                hijo++;
            }

            if(numeros[j] >= numeros[hijo]) {
                break;
            }

            aux = numeros[j];
            numeros[j] = numeros[hijo];
            numeros[hijo] = aux;

            j = hijo;
        }
    }

    // Ordenar
    for(i = n - 1; i > 0; i--) {

        aux = numeros[0];
        numeros[0] = numeros[i];
        numeros[i] = aux;

        j = 0;

        while(2 * j + 1 < i) {

            hijo = 2 * j + 1;

            if(hijo + 1 < i && numeros[hijo + 1] > numeros[hijo]) {
                hijo++;
            }

            if(numeros[j] >= numeros[hijo]) {
                break;
            }

            aux = numeros[j];
            numeros[j] = numeros[hijo];
            numeros[hijo] = aux;

            j = hijo;
        }
    }
}
void mostrar(int numeros[], int n) {

    for(int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;
}
int main() {

    int numeros[100];
    int n;
    int opcion;

    cout << "       METODOS DE ORDENAMIENTO" << endl;

    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    cout << endl;
    cout << "Ingrese los numeros:" << endl;

    for(int i = 0; i < n; i++) {

        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    do {

        cout << endl;
        cout << "                 MENU" << endl;
        cout << "Seleccione una opcion" << endl;
        cout << "1. Ordenamiento por burbuja" << endl;
        cout << "2. Ordenamiento por insercion" << endl;
        cout << "3. Ordenamiento por seleccion" << endl;
        cout << "4. 0rdenamiento por mezcla" << endl;
        cout << "5. Ordenamiento rapido" << endl;
        cout << "6. Ordenamiento por monticulo" << endl;
        cout << "7. Mostrar arreglo" << endl;
        cout << "8. Salir" << endl;

        cout << "Ingrese el numero del metodo de ordenamiento que desea: ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                bubbleSort(numeros, n);

                cout << endl;
                cout << "ordenamiento por burbuja:" << endl;
                mostrar(numeros, n);

                break;

            case 2:

                insertionSort(numeros, n);

                cout << endl;
                cout << "Ordenamiento por insercion:" << endl;
                mostrar(numeros, n);

                break;

            case 3:

                selectionSort(numeros, n);

                cout << endl;
                cout << "Ordenamiento por seleccion:" << endl;
                mostrar(numeros, n);

                break;

            case 4:

                mergeSort(numeros, 0, n - 1);

                cout << endl;
                cout << "0rdenamiento por mezcla:" << endl;
                mostrar(numeros, n);

                break;

            case 5:

                quickSort(numeros, 0, n - 1);

                cout << endl;
                cout << "Ordenamiento rapido:" << endl;
                mostrar(numeros, n);

                break;

            case 6:

                heapSort(numeros, n);

                cout << endl;
                cout << "Ordenamiento por monticulo:" << endl;
                mostrar(numeros, n);

                break;

            case 7:

                cout << endl;
                cout << "Arreglo actual:" << endl;
                mostrar(numeros, n);

                break;

            case 8:

                cout << endl;
                cout << "Programa finalizado." << endl;

                break;

            default:

                cout << endl;
                cout << "Opcion incorrecta." << endl;
        }

    } while(opcion != 8);

    return 0;
}