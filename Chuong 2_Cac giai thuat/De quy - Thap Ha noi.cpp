#include <iostream>
using namespace std;

void thapHaNoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout <<"Cot "<< source << " --> cot " << destination << endl;
        return;
    }
    thapHaNoi(n - 1, source, auxiliary, destination);
    thapHaNoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;

    cout << "Cac buoc di chuyen de giai bai toan Thap Ha Noi voi " << n << " dia:" << endl;
    thapHaNoi(n, 'A', 'C', 'B'); 
    
    return 0;
}

