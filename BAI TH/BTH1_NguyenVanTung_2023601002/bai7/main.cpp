#include <iostream>
using namespace std;

long long f[1000];

long long fib(int n) {
    if (n <= 2) return 1;
    if (f[n] != 0) return f[n];
    f[n] = fib(n - 1) + fib(n - 2);
    return f[n];
}

int main() {
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
