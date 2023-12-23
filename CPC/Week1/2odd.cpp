#include <iostream>
#include <vector>

using namespace std;

void printTwoOdd(int arr[], int size) {
    // XOR all elements to find the XOR of the two odd occurring numbers
    int XOR = arr[0];
    for (int i = 1; i < size; i++) {
        XOR ^= arr[i];
    }

    // Find the rightmost set bit in XOR
    int rightmostSetBit = XOR & -XOR;

    // Initialize two numbers with XOR of two odd occurring numbers
    int num1 = 0, num2 = 0;

    // Divide the array into two groups based on the rightmost set bit
    for (int i = 0; i < size; i++) {
        if (arr[i] & rightmostSetBit) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
    }

    cout << "The two ODD elements are " << num1 << " and " << num2;
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printTwoOdd(arr, arr_size);

    return 0;
}
