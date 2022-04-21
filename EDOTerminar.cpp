#include <iostream>
#include <vector>
# include <cmath>
// Información de <vector> sacada dehttps://www.codesdope.com/cpp-stdvector/

double f(double x);
double fp(double x);
void eu(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y);
void rk4(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y);

int main(){

    double xi = 0, xf = 2, n = 20, yi = 1;
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
    
    std::cout.precision(5);
    for (int i = 0; i <= n; i++){
        std::cout<< y.at(i) << "\t\t" << rk.at(i) <<"\t\t" << euler.at(i) << "\n";
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
        y.push_back(y.at(i-1)*(1-h));
    }       
    
}

void rk4(double xi, double xf, int n, std::vector<double> &x, std::vector<double> &y){

    double h = (x.back()-x.front())/n;
    
    for (int i = 1; i <= n; i++){
        double k1 = h*f(y.at(i-1))
        y.push_back();
    }       
    
}