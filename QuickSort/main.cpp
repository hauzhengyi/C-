#include <iostream>
#include <stdlib.h>
#include <ctime>
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

int main()
{
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand()%SIZE;
    }

    quickSort(arr, 0, SIZE - 1);

    return 0;
}
