#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

//initiations
const double stock_price = 1;
const double number_of_stocks = 100;
const double sig = 0.3;
const double r = 0.03;
const double K = 1;
const double error = 0.00001;
const double steps = 100;
const double timestep = 0.01;

double call;

unsigned seed = time(NULL);
std::default_random_engine generator(seed);
std::normal_distribution<double> distribution(0, sqrt(timestep));

void SimpleMonteCarlo1(double ori_spot, int numberOfPaths,int numOfSteps) {
    for(int path = 0; path < numberOfPaths; path++) {
        double spot = ori_spot;
        for (int steps = 0; steps < numOfSteps; steps++) {
            cout << spot << ", ";
            double wiener_motion = distribution(generator);
            spot = spot * exp(wiener_motion - 0.5*timestep);
        }
        cout << endl;
    }
    return;
}

int main()
{
    double spot;
    int numberOfPaths;
    int numOfSteps;
    cin >> spot;
    cin >> numberOfPaths;
    cin >> numOfSteps;
    SimpleMonteCarlo1(spot, numberOfPaths, numOfSteps);
}