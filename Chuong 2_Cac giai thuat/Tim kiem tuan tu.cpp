#include <iostream>
using namespace std;

// Ham tim kiem tuan tu
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Tra ve chi so cua phan tu tim thay
        }
    }
    return -1; // Khong tim thay
}

int main() {
    int arr[] = {2,0,0,4,2,0,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = linearSearch(arr, n, x);
    if (result != -1) {
        cout << "Phan tu " << x << " duoc tim thay tai vi tri " << result << "." << endl;
    } else {
        cout << "Khong tim thay phan tu " << x << " trong mang." << endl;
    }
    return 0;
}

