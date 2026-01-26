#include <iostream>
using namespace std;

void ThapHaNoi_DeQuy(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Chuyen 1 dia tu " << a << " sang " << c << endl;
    } else {
        ThapHaNoi_DeQuy(n - 1, a, c, b); // Chuyen n-1 dia A -> B
        cout << "Chuyen 1 dia tu " << a << " sang " << c << endl; // Chuyen dia to nhat A -> C
        ThapHaNoi_DeQuy(n - 1, b, a, c); // Chuyen n-1 dia B -> C
    }
}

int main() {
    int n;
    cout << "Nhap so dia: "; cin >> n;
    ThapHaNoi_DeQuy(n, 'A', 'B', 'C');
    return 0;
}
