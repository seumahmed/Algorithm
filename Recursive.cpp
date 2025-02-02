/*write a c++ code to calculate the sum of all positive integers from 1 to N resursively.
Explain the base case and recursive step in your code and provide an example of how to call
this function to find the sum of positive integers up to a given value.*/


#include <iostream>
using namespace std;


int recSum(int N) {
    // Base case: if N is 1, return 1
    if (N == 1) {
        return 1;
    }
    // Recursive step: add N to the sum of integers from 1 to N-1
    else {
        return recSum(N - 1) + N;
    }
}

int main() {
    int N;
   cout << "Enter a positive integer: ";
   cin >> N;

    int result = recSum(N);
    cout << "The sum of positive integers up to " << N << " is: " << result << endl;

    return 0;
}


/*In this code, the base case is when N is 1, where we simply return 1. The recursive step is to add N to the sum of integers from 1 to N-1, which is done by calling the `calculateSum` function recursively.

To find the sum of positive integers up to a given value, you can call the `calculateSum` function with the desired value as the argument. For example, to find the sum up to 5,
 you can use `calculateSum(5)*/







