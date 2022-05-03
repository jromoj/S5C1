#include <iostream>
#include <vector>
# include <cmath>
// Información de <vector> sacada dehttps://www.codesdope.com/cpp-stdvector/

double f(double x);
double fp(double x);
void eu(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y);
void rk4(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y);

int main(){

    double xi = 0.0, xf = 2.0, n = 80.0, yi = 1.0;
    double h = (xf-xi)/n;
    
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> euler;
    std::vector<double> rk;
    euler.push_back(yi);
    rk.push_back(yi);
    
    for (int i = 0; i <= n; i++){
        x.push_back(i*h);
        y.push_back(f(x.at(i)));
    }

    eu(xi,xf,n,x,euler);
    rk4(xi,xf,n,x,rk);
    
    std::cout.precision(5);
    for (int i = 0; i <= n; i++){
        std::cout<< y.at(i) <<"\t\t" << euler.at(i) << "\t\t" << rk.at(i) << "\n";
    }
    
    return 0;
}

double f(double x){
    return exp(-x);
}

double fp(double x){
    return -x;
}

void eu(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y){

    double h = (x.back()-x.front())/n;
    
    for (int i = 1; i <= n; i++){
        y.push_back(y.at(i-1)+(h*fp(y.at(i-1))));
    }       
    
}

void rk4(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y){

    double h = (x.back()-x.front())/n;
    
    for (int i = 1; i <= n; i++){
        double k1 = h*fp(y.at(i-1));
        double k2 = h*fp(y.at(i-1)+(k1/2.0));
        double k3 = h*fp(y.at(i-1)+(k2/2.0));
        double k4 = h*fp(y.at(i-1)+k3);
        y.push_back(y.at(i-1)+(k1+(2*k2)+(2*k3)+k4)/6.0);
    }       
    
}