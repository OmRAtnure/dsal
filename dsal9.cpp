#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]); 

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n=arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter number of element:";
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
    cout<<"Enter array elements: ";
        int value;
        cin>>value;
        arr.push_back(value);
    }

    cout << "Unsorted array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}