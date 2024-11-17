#include <iostream>
using namespace std;

// Ham sap xep chen
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Dich chuyen cac phan tu lon hon key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Chen key vao vi tri dung
    }
}

int main() {
    int arr[] = {2,0,0,4,2,0,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Mang sau khi sap xep chen: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

