#include <iostream>
#include <vector>
#include <cmath>

//Solución exacta
double f(double x);
double ffric(double x);
double fp(double x);

//Ecuaciones a resolver vp sin fricción, vp2 con fricción
double vp(double y);
double vp2(double y, double v);

//Soluciones 2 para fricción
void LF(std::vector<double> &v, std::vector<double> &y);
void eu(std::vector<double> &v, std::vector<double> &y);
void rk4(std::vector<double> &v, std::vector<double> &y);
void eu2(std::vector<double> &v, std::vector<double> &y);
void rk42(std::vector<double> &v, std::vector<double> &y);

//Función para calcular energía
void E(std::vector<double> &v, std::vector<double> &y, std::vector<double> &e);

//Variables globales
double m = 0.2, k = 50.0, fr = 0.08;
double w = sqrt(k/m);
double xi = 0.0, xf = 2.5, n = 2000.0;
double h = (xf-xi)/n;

int main(){
    
    double y0 = 0.1, v0 = 0;
    
    std::vector<double> x;
	std::vector<double> v;
    std::vector<double> y;
    std::vector<double> yfric;
	
	y.push_back(y0);
    yfric.push_back(y0);
    v.push_back(v0);
    x.push_back(0);
    
// Vectores con la solución
    std::vector<double> lf;
    std::vector<double> eul;
    std::vector<double> rk;
    std::vector<double> eul2;
    std::vector<double> rk2;
    
// Vectores con la energía
    std::vector<double> Ereal;
    std::vector<double> Elf;
    std::vector<double> Eeul;
    std::vector<double> Erk;
    
    lf.push_back(y0);
    eul.push_back(y0);
    rk.push_back(y0);
    eul2.push_back(y0);
    rk2.push_back(y0);
    
    for (int i = 1; i <= n; i++){
        x.push_back(i*h);
        double a = f(x.at(i));
        double b = fp(x.at(i));
        double c = ffric(x.at(i));
        
        y.push_back(a);
        yfric.push_back(c);
        v.push_back(b);
        
    }
    
    E(v, y, Ereal);
    
    v.clear();
    v.push_back(v0+((h/2)*vp(y0)));
    LF(v,lf);
    E(v, lf, Elf);
    
    v.clear();
    v.push_back(v0);
    eu(v,eul);
    E(v, lf, Eeul);
    
    v.clear();
    v.push_back(v0);
    rk4(v,rk);
    E(v, lf, Erk);
    
// Solución con fricción
    v.clear();
    v.push_back(v0);
    eu2(v,eul2);
    
    v.clear();
    v.push_back(v0);
    rk42(v,rk2);
    
	std::cout.precision(5);
    
    for (int i = 0; i <= n; i++){
        std::cout<< x.at(i) << "\t\t" << y.at(i) << "\t\t" << eul.at(i) << "\t\t" << rk.at(i) << "\t\t" << lf.at(i) << "\t\t" << Ereal.at(i) << "\t\t" << Eeul.at(i) << "\t\t" << Erk.at(i) << "\t\t" << Elf.at(i) << "\t\t" << yfric.at(i) << "\t\t" << eul2.at(i) << "\t\t" << rk2.at(i) << "\n";
    }

    return 0;
}

double f(double x){
    return (0.1*cos(w*x));
}

double ffric(double x){
    return exp(-0.04*x)*(0.1*cos(w*x));
}

double fp(double x){
    return (-(0.1*w)*sin(w*x));
}

double vp(double y){
	return (-(k/m)*y);
}

double vp2(double y, double v){
	return (-(k/m)*y)-(fr*v);
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

        v.push_back(v.at(i-1)+(h*vp(y.at(i-1))));
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
        
    }       
    
}

void rk4(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
        
        double k1 = h*vp(y.at(i-1));
        double k2 = h*vp(y.at(i-1)+(k1/2.0));
        double k3 = h*vp(y.at(i-1)+(k2/2.0));
        double k4 = h*vp(y.at(i-1)+k3);
        
        v.push_back(v.at(i-1)+((k1+(2*k2)+(2*k3)+k4)/6.0));
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
    
    }       
    
}

void E(std::vector<double> &v, std::vector<double> &y, std::vector<double> &e){

    for (int i = 0; i <= n; i++){
        
        double T = (m/2.0)*pow(v.at(i), 2.0);
        double V = (k/2.0)*pow(y.at(i), 2.0);
        
        e.push_back(T+V);
    
    }       
}

void eu2(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
            
        v.push_back(v.at(i-1)+(h*vp2(y.at(i-1),v.at(i-1))));
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
        
    }       
    
}

void rk42(std::vector<double> &v, std::vector<double> &y){
    
    for (int i = 1; i <= n; i++){
        
        double k1 = h*vp2(y.at(i-1),v.at(i-1));
        double k2 = h*vp2((y.at(i-1)+(k1/2.0)),v.at(i-1));
        double k3 = h*vp2((y.at(i-1)+(k2/2.0)),v.at(i-1));
        double k4 = h*vp2((y.at(i-1)+k3),v.at(i-1));
    
        v.push_back(v.at(i-1)+((k1+(2*k2)+(2*k3)+k4)/6.0));
        y.push_back(y.at(i-1)+(h*v.at(i-1)));
    
    }       
    
}