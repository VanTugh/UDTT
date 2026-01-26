#include <iostream>
using namespace std;

int n;
char a[100];

void sinhChuoi(int i) {
    for (char c : {'a', 'b'}) {
        a[i] = c;
        if (i == n) {
            for (int j = 1; j <= n; j++)
                cout << a[j];
            cout << endl;
        } else {
            sinhChuoi(i + 1);
        }
    }
}

int main() {
    cin >> n;
    sinhChuoi(1);
    return 0;
}
