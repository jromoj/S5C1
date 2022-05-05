#include <iostream>
#include <vector>
#include <cmath>

// Variables globales y condiciones iniciales (Extremos fijos)
double c = 300, L = 2, n = 100, dx = L/(n-1), dt = dx/(2*c-1);
double X0 = 0, XL = 0, Tf = 0.1, k = pow(c*dt/dx,2.0);

// Función para inicializar la cuerda
void init(std::vector<double> &x0, std::vector<double> &x1);

// Función para calcular cuerda en t + dt
void tstep(std::vector<double> &x0, std::vector<double> &x1, std::vector<double> &x2);

// Solución total de la cuerda
void cuerda(std::vector<double> &sol);

int main(){
  
    std::vector<double> sol;
    std::vector<double> x;
    cuerda(sol);
    
    for (int i = 0; i <= n; i++){
        x.push_back(dx*i);
    }
    return 0;
  
    for (int i = 0; i <= n; i++){
        std::cout<< x.at(i) << "\t\t" << sol[0].at(i) << "\t\t" << sol[20].at(i) << "\t\t" << sol[50].at(i) << sol[100].at(i) << "\t\t" << sol[150].at(i) << "\t\t" << sol[200].at(i) << "\n";
    }
}

void init(std::vector<double> &x0, std::vector<double> &x1){

    x0.push_back(0);
    x1.push_back(0);
  
    // t = 0
    for (int i = 1; i < n; i++){
    
        if (dx*i >= L/2){
            x0.push_back(x0.at(i-1)-(dx*0.1));
        }
        else x0.push_back(x0.at(i-1)+(dx*0.1));
    
    }
    x0.push_back(0);
  
    // t = dt con Ut(x,0) = 0
    double x = 0;
    for (int i = 1; i < n; i++){
    
        double a1 = x0.at(i), a2 = x0.at(i+1), a3 = x0.at(i), a4 = x0.at(i-1);
        x = a1 + 0.5*k*(a2 - 2*a3 + a4);
        x1.push_back(x); 
    
    }
    x1.push_back(0);
}
  
void tstep(std::vector<double> &x0, std::vector<double> &x1, std::vector<double> &x2){

    double x = 0;
    x2.push_back(0);
    for (int i = 1; i < n; i++){

        x = 2*x1.at(i) - x0.at(i)*k*(x1.at(i+1) - 2*x1.at(i) + x1.at(i-1));
        x2.push_back(x);  
        
    }
    x2.push_back(0);
}

void cuerda(std::vector<double> &sol){

    std::vector<double> y0;
    std::vector<double> y1;
    std::vector<double> y2;
  
    init(y0,y1);
    tstep(y0,y1,y2);
    sol.push_back(y0);
    sol.push_back(y1);
    sol.push_back(y2);
  
    for (int i = dt; i < Tf; i += dt){

        y0 = y1;
        y1 = y2;
        tstep(y0,y1,y2);
        sol.push_back(y2);
    }
}
