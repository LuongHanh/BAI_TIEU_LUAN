#include <iostream>
using namespace std;

// Ham de quy tinh so luong tho
int countRabbits(int n) {
    if (n <= 1) {
        return 1; // Co so: 1 cap tho ban dau
    }
    return countRabbits(n - 1) + countRabbits(n - 2); // De quy
}

int main() {
    int months;
    cout << "Nhap so thang: ";
    cin >> months;
    cout << "So luong tho sau " << months << " thang la: " << countRabbits(months) << endl;
    return 0;
}

