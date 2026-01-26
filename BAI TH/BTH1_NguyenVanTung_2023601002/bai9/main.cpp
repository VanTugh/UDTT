#include <iostream>
using namespace std;

int tongChuSo(int n) {
    if (n == 0) return 0;
    return n % 10 + tongChuSo(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << tongChuSo(n);
    return 0;
}
