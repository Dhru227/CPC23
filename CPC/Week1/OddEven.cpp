#include <iostream>
using namespace std;

// Function to swap elements at given indices
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to segregate even and odd numbers
void segregateEvenOdd(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        // Increment left index while the element at left index is even
        while (arr[left] % 2 == 0 && left < right)
            left++;

        // Decrement right index while the element at right index is odd
        while (arr[right] % 2 == 1 && left < right)
            right--;

        // If left < right, swap the elements at left and right indices
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    segregateEvenOdd(arr, size);

    cout << "Array after segregating even and odd numbers: ";
    printArray(arr, size);

    return 0;
}
