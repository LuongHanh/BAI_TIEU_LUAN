#include <iostream>
using namespace std;

// Ham de quy tinh giai thua
int factorial(int n) {
    if (n == 0) // Diem dung
        return 1;
    return n * factorial(n - 1); // Cong thuc de quy
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    if (n < 0)
        cout << "Giai thua khong xac dinh cho so am." << endl;
    else
        cout << "Giai thua cua " << n << " la: " << factorial(n) << endl;

    return 0;
}

