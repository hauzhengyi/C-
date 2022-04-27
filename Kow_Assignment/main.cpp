#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

const double T = 1;
const double E = 11;
const double t_int = 0.00001;
const double S0 = 10;
const double sig = 0.2;
const int population = 100;
double total_ST = 0;
double total_c = 0;
double total_cd = 0;
double total_v = 0;
double total_w = 0;

double grow(double &);
double B(double &);

unsigned seed = time(NULL);
std::default_random_engine generator(seed);
std::normal_distribution<double> distribution(0.0, sqrt(t_int));

int main() {

    std::cout << std::setprecision(5);
    vector<double> ST(population, S0);

    cout << "S(T)\t\tc\t\tcd\t\tv\t\tw" << endl;

    for(vector<double>::iterator it = ST.begin(); it != ST.end(); it++) {
        
        double maxim = grow(*it);
        //cout << (double)*it << "\t\t";

        if(*it > E) {
            //cout << *it - E << "\t\t" << 1 << "\t\t";
            total_c += *it - E;
            total_cd += 1;
        }
        else {
            //cout << 0 << "\t\t" << 0 << "\t\t";
        }
        if(maxim > E) {
            //cout << maxim - E << "\t\t" << 1 << endl;
            total_v += maxim - E;
            total_w += 1;
        }
        else {
            //cout << 0 << "\t\t" << 0 << endl;
        }
        total_ST += *it;
    }
    cout << "Avg: " << total_ST / (double)population << "\t";
    cout << "Avg: " << total_c / (double)population << "\t";
    cout << "Avg: " << total_cd / (double)population << "\t";
    cout << "Avg: " << total_v / (double)population << "\t";
    cout << "Avg: " << total_w / (double)population << endl;
    cout << "v/c ratio: " << (double)(total_v / total_c) << endl;
    cout << "w/cd ratio: " << (double)(total_w / total_cd) << endl;
    return 0;
}

double grow(double &price) {
    double maxim = 0;
    for(double t = 0; t < T; t += t_int) {
        double B = distribution(generator);
        price = price*exp(sig*sig*t_int/2+sig*B);
        if(price > maxim)
            maxim = price;
    }
    return maxim;
}