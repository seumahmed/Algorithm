#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int arr[], int n, int targetElement) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == targetElement) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetElement = 185;
    int result = linearSearch(arr, n, targetElement);
    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index: " << result << " " << endl;
    }
    return 0;
}
