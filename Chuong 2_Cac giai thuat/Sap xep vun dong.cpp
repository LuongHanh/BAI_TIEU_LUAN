#include <iostream>
using namespace std;

// Ham vun dong
void heapify(int arr[], int n, int i) {
    int largest = i;      // Goc ban dau
    int left = 2 * i + 1; // Con trai
    int right = 2 * i + 2;// Con phai

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Ham sap xep vun dong
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Xay dung max-heap
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Hoan doi phan tu lon nhat
        heapify(arr, i, 0);   // Vun dong lai
    }
}

int main() {
    int arr[] = {2,0,0,4,2,0,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Mang sau khi sap xep vun dong: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

