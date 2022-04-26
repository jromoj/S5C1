#include <iostream>
#include <vector>
# include <cmath>
// Información de <vector> sacada dehttps://www.codesdope.com/cpp-stdvector/

//Solución eacta
double f(double x);

//Ecuaciones a resolver
double vp(double y);
double v(double y);

//Leap Frog
void LF(std::vector<double> &x, std::vector<double> &v, std::vector<double> &y);

//Variables globales
double m = 0.2, k = 50.0, y0 = 0.1, v0 = 0; 
double w = sqrt(k/m);
double xi = 0.0, xf = 8.0, n = 80.0;
double h = (xf-xi)/n;

int main(){
    
    std::vector<double> x;
	std::vector<double> v;
    std::vector<double> y;
	
    std::vector<double> lf;
	
    
    for (int i = 0; i <= n; i++){
        x.push_back(i*h);
        y.push_back(f(x.at(i)));
    }

    LF(x,v,y);
    
	std::cout.precision(5);
    for (int i = 0; i <= n; i++){
        std::cout<< y.at(i) << "\t\t" << lf.at(i) << "\n";
    }
    
    return 0;
}

double f(double x){
    return (0.1*cos(w*x));
}

double vp(double y){
	return -(k/m)*y;
}
double v(double y){
	return 0;
}

void LF(std::vector<double> &x, std::vector<double> &v, std::vector<double> &y){
	
	//double y0 = 0.1, v0 = 0;
    v.push_back(0);
	y.push_back(0.1);
    
    for (int i = 1; i <= n; i++){
	
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
		v.push_back(v.at(i-1)+(h*vp(y.at(i-1))));
    }           
}

/*
Escriba un código en C++ usando sus implementaciones de Euler y Runge Kutta de 4to orden para resolver la ecuación de segundo orden de un oscilador armónico:


Imprima las soluciones en archivo(s) y grafique sus resultados usando un script de Python PLOTS_NombreApellido_S7C1_EDO2.py.
Haga un Makefile Makefile_ApellidoNombre_S7C1_EDO2.mk que genere las gráficas a partir de los scripts en C++ y en Python
Ahora implemente en C++ el método de Leap Frog para resolver la ecuación la ecuación de los puntos anteriores.
Compare sus resultados.
Si les queda tiempo, resuelva ahora el caso de un oscilador amortiguado por una fuerza de fricción (usando Euler y Runge-Kutta de 4to orden) con las mismas condiciones iniciales anteriores y con b=0.08:
*/