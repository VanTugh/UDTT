#include <iostream>
using namespace std;

// Hàm đệ quy tìm UCLN
int UCLN(int a, int b) {
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;

    }
    return a;
}

int main() {
    int a, b;
    cout << "Nhap a, b: "; cin >> a >> b;
    cout << "UCLN (De quy): " << UCLN(a, b);
    return 0;
}
