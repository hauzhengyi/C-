#include <iostream>
#include <stdlib.h>
#include <ctime>
#define SIZE 10000

using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]){
                int temp = arr[i];
                for(int k = i; k > j; k--){
                    arr[k] = arr[k-1];
                }
                arr[j] = temp;
                break;
            }
        }
    }
}

int main()
{
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
    }

    insertionSort(arr, SIZE);

    return 0;
}
