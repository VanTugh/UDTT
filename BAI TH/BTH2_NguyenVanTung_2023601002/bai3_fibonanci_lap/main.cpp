#include <iostream>
using namespace std;

long long Fibo_Lap(int n) {
    if (n < 3) return 1;
    long long t1 = 1, t2 = 1, tn;
    for (int i = 3; i <= n; i++) {
        tn = t1 + t2;
        t1 = t2;
        t2 = tn;
    }
    return tn;
}

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    cout << "Fibo thu " << n << ": " << Fibo_Lap(n);
    return 0;
}
