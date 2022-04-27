#include <iostream>
#include <math.h>

using namespace std;

const double S = 20.0;
const double time = 4.0;
const double n = 1000000;
const double m = 200000;
const double sig = 0.3;
const double r = 0.03;
const double K = 60.0;
const double error = 0.00001;

double W = 20;
double Wnew = 1;
double d1 = 0;
double d2 = 0;
double Nd1, Nd2;
double gw, gwd;
double call = 0;

double normal_distribution(double d) {
    return 0.5*erfc(-d/sqrt(2.0));
}

int main() {
    while(true) {

        d1 = ( log((S+m/n*W)/K) + (r+0.5*sig*sig) * (time) ) / (sig*pow(time, 0.5) );
        d2 = ( log((S+m/n*W)/K) + (r-0.5*sig*sig) * (time) ) / (sig*pow(time, 0.5) );

        Nd1 = normal_distribution(d1);
        Nd2 = normal_distribution(d2);

        call = (S+(m/n)*W) * Nd1 - exp(-r*time)*K*Nd2;
        gw = W-n*call/(n+m);
        gwd = 1 - m*Nd1/(n+m);
        Wnew = W - gw/gwd;

        if( abs(Wnew - W) < error ) {
            W = Wnew;
            break;
        }

        W = Wnew;
    }
    
    cout << "Wnew = " << Wnew << endl;

    return 0;
}