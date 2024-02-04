#include<bits/stdc++.h>
using namespace std;

bool isMajority(int arr[], int n, int x) {
	int last_index = n % 2 ? (n / 2 + 1) : (n / 2);
	for (int i = 0; i < last_index; i++) {
		if (arr[i] == x && arr[i + n / 2] == x)
			return true;
	}
	return false;
}

int main() {
	int arr[] ={1, 2, 3, 4, 4, 4, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	if (isMajority(arr, n, x))
		cout << x << " appears more than " << n / 2 << " times in arr[]" << endl;
	else
		cout << x << " does not appear more than " << n / 2 << " times in arr[]" << endl;
	return 0;
}
