/*
Scrivi una funzione che prende in input un array di interi e la sua dimensione, e restituisce:
    Il valore massimo
    L'indirizzo del valore massimo
    La somma totale
*/

#include <iostream>
#include <cstdlib>

void ex1(int *arr, int dim){
    int sum_tot = 0;
    int maxx = *arr;
    for (int i=0; i<dim; i++){
        std::cout << *(arr+i) << std::endl;
        if (*(arr+i) > maxx){  maxx = *(arr+i); }
        sum_tot += *(arr+i);
    }
    std::cout << "Max val: " << maxx << ", &:" << &maxx << ", sum total: " << sum_tot << std::endl;
    return;
}



/*
Scrivi una funzione void swap(int* a, int* b) che scambi i valori puntati.
Poi testala nel main() con due variabili.
*/

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
Alloca dinamicamente un array di n float, inizializzalo con valori casuali (tra 0.0 e 10.0), e stampalo.
Ricorda di liberare la memoria con delete[].
*/

void ex3(int n){
    float *array = new float[n];
    for (int i=0; i<n; i++){
        *(array+i) = rand() % 10;
        std::cout << "i: " << *(array+i) << std::endl;
    }
    delete[] array;
}


//  Dichiara un void* ptr, assegnagli l’indirizzo di un int, poi castalo per stampare il valore.
void ex4(){
    int x = 10;
    void *ptr = &x;
    std::cout << "Address of value: " << static_cast<int*>(ptr) << std::endl;
    std::cout << "Value: " << *(static_cast<int*>(ptr)) << std::endl; // deferenziazione
}


/*
Scrivi una funzione void resizeArray(int*& arr, int oldSize, int newSize) che alloca un nuovo array più grande, copia i vecchi valori e aggiorna il puntatore.
*/
void resizeArray(int*& arr, int oldSize, int newSize){
    int *newArr = new int[newSize];
    // Copia i vecchi valori (fino al minimo fra oldSize e newSize)
    int limit = (oldSize < newSize ? oldSize : newSize);
    for (int i = 0; i < limit; i++) {
        newArr[i] = arr[i];
    }

    // Rilascia la vecchia memoria
    delete[] arr;

    // Aggiorna il puntatore passato per riferimento
    arr = newArr;
}


/*
8.
Requisito:
    Dato int arr[5] = {1,2,3,4,5};, scrivi un ciclo for che usa solo puntatori per stampare i valori e gli indirizzi.

9. Somma tra due array di float
Requisito:
    Scrivi una funzione che prende due array float* e ne restituisce un terzo con la somma elemento per elemento.

*/

void ex8(int arr[5] ){
    int *p_arr = &arr[0];
    for (int i = 0; i<5; i++){
        std::cout << "Value: " << *(p_arr+i) << ", address: "<< (p_arr+i) << std::endl;
    }
}

void ex9(float *arr1, float *arr2, int n){
    float *arr3 = new float[n];
    for (int i=0; i<n; i++){
        *(arr3+i) = (*(arr1+i)+*(arr2+i));
        std::cout << "Pos i: " << i << ", value: " << *(arr3+i) <<std::endl;
    }

}



int main(){
    //int arr[5] = {9, 2, 10, 50, 1};
    //ex1(&arr[0], 5);

    /*int a = 5; int b = 10;
    std::cout << "a: " <<  a << ", b: " << b << std::endl;
    
    swap(&a, &b);

    std::cout << "a: " <<  a << ", b: " << b;
    */

    //ex3(10);
    //ex4();

    //int arr[5] = {1,2,3,4,5};
    //ex8(arr);

    float arr1[4] = {1.0, 2.0, 3.0, 4.0};
    float arr2[4] = {1.0, 2.0, 3.0, 4.0};
    ex9(&arr1[0], &arr2[0], 4);


}

