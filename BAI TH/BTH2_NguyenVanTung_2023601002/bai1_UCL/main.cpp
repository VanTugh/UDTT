#include <iostream>
using namespace std;

// Hàm đệ quy tìm UCLN
int UCLN_DeQuy(int a, int b) {
    if (b == 0) return a;
    return UCLN_DeQuy(b, a % b);
}

int main() {
    int a, b;
    cout << "Nhap a, b: "; cin >> a >> b;
    cout << "UCLN (De quy): " << UCLN_DeQuy(a, b);
    return 0;
}
