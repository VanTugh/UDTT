#include <iostream>
using namespace std;

long long Fibo_DeQuy(int n) {
    if (n < 3) return 1;
    return Fibo_DeQuy(n - 1) + Fibo_DeQuy(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    cout << "Fibo thu " << n << ": " << Fibo_DeQuy(n);
    return 0;
}
