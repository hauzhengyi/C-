#include <iostream>

using namespace std;

int n, partSize, sum = 0;


bool partition(int [], int [], int, int);

int main() {
    cin >> n;
    int array[n];
    int used[n] = {0};
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }
    int k;
    cin >> k;

    if(sum % k || k <= 0) {
        cout << "False";
        return 0;
    }
    // the sum of the array elements should be divisible by k

    partSize = sum / k;
    // we need to partition the numbers into k
    // partitions of this size

    if(partition(array, used, k, 0))
        cout << "True";
    else
        cout << "False";

    return 0;
}

bool partition(int array[], int used[], int k, int currSize) {
    if(k == 1) return true;
    // every time a partition is completed, k will decrease by 1
    // until k equals to 1, we know the the rest will form a
    // partition of equal sum, therefore we can return true

    for(int i = 0; i < n; i++) {

        if(used[i]) continue;
        // check if the number is used

        if(array[i] > partSize) return false;
        // if the number is greater than the size of the
        // partition, there can be no way to partition them

        currSize += array[i];
        // add the current element to the building partition
        
        if(currSize > partSize) {
            currSize -= array[i];
            continue;
        }
        // if the current partition exceeds the target size,
        // remove the element back

        if(currSize == partSize) {
            used[i] = 1;
            if(partition(array, used, k - 1, 0))
                return true;
            currSize -= array[i];
            used[i] = 0;
            continue;
        }
        // if the current partition is same as the target size,
        // mark it as used and call the function with k-1

        if(currSize < partSize) {
            used[i] = 1;
            if(partition(array, used, k, currSize))
                return true;
            currSize -= array[i];
            used[i] = 0;
            continue;
        }
        // if the current partition is still smaller than the
        // target size, mark the element as used and continue
        // calling the function
    }

    return false;
}