#include <iostream>

// Variables globales
int a = 3;
float b = 9.6;

int sum(float mivarflotante, int mivarentera);
int min(int ar[]);
int menorque(int ar[], int max);
    
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
    std::cout << "El arreglo tiene " << (sizeof(arr)/sizeof(int) + 1) << " elementos" << "\n";
    
// Función con variable float y entera para 17.5 y 5
    sum(17.5,5);
    
// Mínimo del arreglo
    min(arr);

// Imprime impares menor que 800
    menorque(arr, 800);
    
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

int menorque(int ar[], int max){
    
    for (int i = 0; i < 300; i++){
        if (ar[i] > max){
            break;
        }
        if (ar[i]%2 == 1){
            std::cout << ar[i] << "\n";
        }
    }
    return 0;
}