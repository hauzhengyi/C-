#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#define SIZE 10000

using namespace std;

void quickSort(int arr[], int first, int last){
    if(first >= last) return;
    int piv = arr[first];
    int i = first;
    int j = last;
    while(i < j){
        while(arr[j] >= piv && i < j)
            j--;
        arr[i] = arr[j];
        while(arr[i] < piv && i < j)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = piv;
    quickSort(arr, first, i);
    quickSort(arr, i+1, last);
    return;
}

// the function f() does some time-consuming work
void f()
{
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand()%SIZE;
    }

    quickSort(arr, 0, SIZE - 1);

    return;
}

int main()
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    std::thread t1(f);
    std::thread t2(f); // f() is called on two threads
    t1.join();
    t2.join();
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
}
