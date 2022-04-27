#include <iostream>
#include <algorithm>

using namespace std;

bool solution(int [], bool [], int []);

int n, k, sum = 0, partSize;
// array length, number of partitions ,sum of all array elements, sum of each partition

int main() {

    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }
    cin >> k;
    // taking inputs from the user

    std::sort(&array[0], &array[n-1]);
    // the algorithm only works with the array sorted

    bool combinations[ 1 << n ] = {0};
    // 1 left-shifted by n bits is 2^n.
    // this array stores different combinations of the elements.
    // For example, if there are 8 elements in array[], one possible combination
    // is the 1st and 3rd element, they can be stored as 00000101, which is 5 in
    // decimals. If this state meets the criteria (explained later),
    // then the 5th element in combinations[] is set to 1.
    // There will then be a total of 2^n different states, hence the 1 << n.
    // The idea is to work our way up to the last element, 11111111, where all
    // elements are used up, and still meets the criteria.
    combinations[0] = true;
    // since 00000000 is 

    int total[1 << n] = {0};
    // this array stores the sum of the elements of a given combination
    // for example, if the 1st and 3rd elements are 2 and 4 correspondingly,
    // then total[5] (5 = 00000101) will be assigned 2 + 4 = 6

    partSize = sum / k;
    // this is the sum of each of the k partitions

    if(solution(array, combinations, total))
        cout << "True";
    else
        cout << "False";

    return 0;
}

bool solution(int array[], bool combinations[], int total[]) {

    for(int state = 0; state < (1 << n); state++) {
        // starting from state 00000000

        if(combinations[state]) {
            // if this state meets the criteria

            for(int i = 0; i < n; i++) {

                int nextState = state | (1 << i);
                // let's say out current state is 00000101,
                // as we iterate through i, we bitwise OR 00000101
                // with 00000001, 00000010, 00000100, 00001000...
                // and so on. This simulates "adding" the ith element
                // to the combinattion.
                // Since the first bit was already 1, the operation
                // 00000101 | 00000001 has no effect on it. 
                // But on the second bit, nextState will be 00000111
                // which is a new state consisting one more element.

                if(nextState == state) continue;

                if(combinations[nextState]) continue;
                // if the new state has already been checked before

                if(array[i] <= partSize - total[state] % partSize) {
                    // the criteria:
                    // array[i] is the element to be added
                    // say if the total of the current combination is 7,
                    // and the partition size is 5, we need 3 to reach the next
                    // multiple of 5, which is 10. Find an element that is <= 3.
                    // If this element is found...

                    combinations[nextState] = true;
                    // we set the new state to true as it has met the criteria

                    total[nextState] = total[state] + array[i];
                    // and we record the sum of the new combination
                }

                else break;
                    // continuing the example,
                    // if we find an element that is > 3,
                    // break the loop, move to the next state.
                    // this is because we sorted the array earlier,
                    // so if further iterations will definitely exceed 3
            }
        }
    }
    // if we keep doing this, and keep finding the next state that
    // meets the criteria, we will eventually reach the last state
    // however, if at some point, there are no more states that meets
    // the criteria, we reach the end with the last state still at 0.
    // the last state determines if we can partition the array into k equal sum subsets
    return combinations[(1 << n) - 1];
}