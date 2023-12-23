#include <bits/stdc++.h>

using namespace std;

vector<int> UnionArray(int arr1[], int arr2[],int n,int m) {
    map<int,int> frequencyMap;


    for (int i = 0; i < n; i++){
        if ( frequencyMap.find(arr1[i]) != frequencyMap.end()) {
            frequencyMap[arr1[i]]++;
        } else {
            frequencyMap[arr1[i]] = 1;
        }
    }

    for(int i = 0; i < m ; i++) {
        if(frequencyMap.find(arr2[i]) != frequencyMap.end()) {
            frequencyMap[arr2[i]]++;
        } else {
            frequencyMap[arr2[i]] = 1;
        }
    }

    vector<int> result;
    for(const auto& entry : frequencyMap){
        result.push_back(entry.first);
    }
    return result;
}

int main() {
    int n, m;

    cout << "Enter the size of array 1: ";
    cin >> n;

    int arr1[n];
    cout << "Enter the elements of array 1 in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of array 2: ";
    cin >> m;

    int arr2[m];
    cout << "Enter the elements of array 2 in sorted order: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }


    vector<int> unionResult = UnionArray(arr1, arr2, n, m);

    cout << "Union is: ";
    for (int num : unionResult) {
        cout << num << " ";
    }

    return 0;
}