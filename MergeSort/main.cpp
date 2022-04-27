#include <iostream>
#include <stdlib.h>
#define SIZE 10000

using namespace std;

void merg(int arr[], int first, int mid, int last){
    int arr2[last-first+1];
    for(int i = first; i <= last; i++){
        arr2[i-first] = arr[i];
    }
    int i = 0, j = mid - first + 1;
    for(int k = first; k <= last; k++){
        if(i > mid - first){
            arr[k] = arr2[j];
            j++;
            continue;
        }
        if(j > last - first){
            arr[k] = arr2[i];
            i++;
            continue;
        }
        if(arr2[i] < arr2[j]){
            arr[k] = arr2[i];
            i++;
            continue;
        }
        if(arr2[j] >= arr2[j]){
            arr[k] = arr2[j];
            j++;
            continue;
        }
    }
}

void mergeSort(int arr[], int first, int last){
    if(first == last) return;
    int mid = (first + last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid+1, last);
    merg(arr, first, mid, last);
}

int main()
{
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
    }

    mergeSort(arr, 0, SIZE - 1);

    return 0;
}
