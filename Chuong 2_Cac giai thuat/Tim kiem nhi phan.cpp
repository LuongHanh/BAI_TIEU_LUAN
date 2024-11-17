#include <iostream>
using namespace std;

// Ham tim kiem nhi phan
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Tim phan tu giua
        if (arr[mid] == x) {
            return mid; // Tim thay gia tri
        }
        if (arr[mid] < x) {
            low = mid + 1; // Tim trong nua phai
        } else {
            high = mid - 1; // Tim trong nua trai
        }
    }
    return -1; // Khong tim thay
}

int main() {
    int arr[] = {2,0,0,4,2,0,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        cout << "Phan tu " << x << " duoc tim thay tai vi tri " << result << "." << endl;
    } else {
        cout << "Khong tim thay phan tu " << x << " trong mang." << endl;
    }

    return 0;
}

