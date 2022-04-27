#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

double Expiry = 1;
unsigned seed = time(NULL);
std::default_random_engine generator(seed);
std::normal_distribution<double> distribution(0, sqrt(Expiry));

double SimpleMonteCarlo1(double Strike,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths)
{
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum=0;
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
        double thisGaussian = distribution(generator);
        thisSpot = movedSpot*exp( rootVariance*thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = (thisPayoff > 0) ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

int main() {
    unsigned seed = time(NULL);
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(  Strike,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);

    cout <<"the price is " << result << "\n";
    double tmp;
    cin >> tmp;
    return 0;
}