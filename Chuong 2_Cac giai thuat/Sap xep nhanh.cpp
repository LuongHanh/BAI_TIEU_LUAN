#include <iostream>
using namespace std;

// Ham hoan doi hai gia tri
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham chia mang va tra ve chi so pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi lam pivot
    int i = low - 1;       // Vi tri cua phan tu nho hon pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Hoan doi phan tu nho hon pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Dua pivot vao dung vi tri
    return i + 1;
}

// Ham sap xep nhanh
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Tim vi tri pivot

        // Goi de quy sap xep hai mang con
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {2,0,0,4,2,0,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep nhanh: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

