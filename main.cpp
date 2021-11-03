#include <iostream>
#include <time.h>
#include <locale.h>
#include <utility>
 
using namespace std;
 
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    
    if (l < n && arr[l] > arr[largest]) { largest = l; }
    if (r < n && arr[r] > arr[largest]) { largest = r; }    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);   
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void showArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    srand(time(NULL));

    cout << "Heap Sort" << endl;
    cout << "García Martínez Braulio Israel 220331615" << endl;

    int noe;
    do{
        cout << "Ingrese la cantidad de datos que desea ordenar: ";
        cin >> noe;

        if( (noe < 2) || (noe >100) ){
            cout << "La cantidad mínima de elementos son 2 y la cantidad máxima son 100" << endl;
        }
    }while( (noe < 2) || (noe > 100) );

    int arr[noe];
    int value;
    for( int i = 0; i < (sizeof arr/sizeof arr[0]); i++ ){
        value = rand() % 10 + 1;
        arr[i] = value;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    
    showArray(arr, n);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    showArray(arr, n);

    return 0;
}