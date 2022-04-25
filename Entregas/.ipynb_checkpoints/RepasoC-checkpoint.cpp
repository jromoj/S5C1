#include <iostream>

// Variables globales
int a = 3;
float b = 9.6;

int sum(float mivarflotante, int mivarentera);
int min(int a[]);
    
int main(){
    
// Imprime las variables globales y b/a
    std::cout << "La primera variable tiene un valor de: " << a << "\n" << "La segunda variable tiene un valor de: " << b << "\n";
    std::cout << "El resultado es: " << b/a << "\n";

// Arreglo de 300 numeros aleatorios entre 0 y 900 y los imprime
    int arr[299];
    for(int i=0; i < 300; i++){
        arr[i] = rand() % 901;
        std::cout << arr[i] << "\n";
    }

// Imprime la longitud del arreglo y el quinto elemento
    std::cout << "El quinto elemento es: " << arr[4] << "\n";
    std::cout << "La longitud del arreglo es: " << sizeof(arr)/sizeof(int) << "\n";
    
// Función con variable float y entera para 17.5 y 5
    sum(17.5,5);
    
// Mínimo del arreglo
    min(arr);
    return 0;
}


int sum(float mivarflotante, int mivarentera){
    std::cout << "La suma es: " << mivarflotante + mivarentera << "\n";
    return 0;
}

int min(int ar[]){
    
    int min = 900;
    
    for (int i = 0; i < 300; i++){
        if (ar[i] < min){
            min = ar[i];
        }
    }
    std::cout << "El número más pequeño es: " << min << "\n";
    return 0;
}
/*

Haga una función que retorne el mínimo del arreglo de números aleatorios antes creado
Haga una función que retorne el arreglo de números aleatorios antes creado, imprima los números impares y pare de imprimir al encontrar un número mayor a 800
*/