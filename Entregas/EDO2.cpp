#include <iostream>
#include <vector>
# include <cmath>

//Solución exacta
double f(double x);

//Ecuaciones a resolver
double vp(double y);

//Soluciones
void LF(std::vector<double> &v, std::vector<double> &y);
void eu(std::vector<double> &v, std::vector<double> &y);
void rk4(std::vector<double> &v, std::vector<double> &y);

//Variables globales
double m = 0.2, k = 50.0;
double w = sqrt(k/m);
double xi = 0.0, xf = 8.0, n = 300.0;
double h = (xf-xi)/n;

int main(){
    
    double y0 = 0.1, v0 = 0;
    
    std::vector<double> x;
	std::vector<double> v;
    std::vector<double> y;
	
    v.push_back(v0+((h/2)*vp(y0)));
	y.push_back(y0);
    x.push_back(0);
    
    std::vector<double> lf;
    std::vector<double> eul;
    std::vector<double> rk;
    
    lf.push_back(y0);
    eul.push_back(y0);
    rk.push_back(y0);
    
    for (int i = 1; i <= n; i++){
        x.push_back(i*h);
        double a = f(x.at(i));
        y.push_back(a);
    }
    
    LF(v,lf);
    eu(v,eul);
    rk4(v,rk);
    
	std::cout.precision(5);
    
    for (int i = 0; i <= n; i++){
        std::cout<< x.at(i) << "\t\t" << y.at(i) << "\t\t" << eul.at(i) << "\t\t" << rk.at(i) << "\t\t" << lf.at(i) <<  "\n";
    }

    return 0;
}

double f(double x){
    return (0.1*cos(w*x));
}

double vp(double y){
	return (-(k/m)*y);
}

void LF(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
        
        double ys = y.at(i-1)+(h*v.at(i-1)); 
        y.push_back(ys);
        
        double vs = v.at(i-1)+(h*vp(y.at(i)));
		v.push_back(vs);
        
    }           
}

void eu(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
        
        v.push_back(v.at(i-1)+(h*vp(v.at(i-1))));
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
        
    }       
    
}

void rk4(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
        
        double k1 = h*vp(v.at(i-1));
        double k2 = h*vp(v.at(i-1)+(k1/2.0));
        double k3 = h*vp(v.at(i-1)+(k2/2.0));
        double k4 = h*vp(v.at(i-1)+k3);
        v.push_back(v.at(i-1)+(k1+(2*k2)+(2*k3)+k4)/6.0);
        
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
    
    }       
    
}

/*

Imprima las soluciones en archivo(s) y grafique sus resultados usando un script de Python PLOTS_NombreApellido_S7C1_EDO2.py.

Haga un Makefile Makefile_ApellidoNombre_S7C1_EDO2.mk que genere las gráficas a partir de los scripts en C++ y en Python


Si les queda tiempo, resuelva ahora el caso de un oscilador amortiguado por una fuerza de fricción (usando Euler y Runge-Kutta de 4to orden) con las mismas condiciones iniciales anteriores y con b=0.08:
*/