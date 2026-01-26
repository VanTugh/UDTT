#include <iostream>
using namespace std;

int n, k;
int a[100];

void tapCon(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            for (int t = 1; t <= k; t++)
                cout << a[t] << " ";
            cout << endl;
        } else {
            tapCon(i + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    a[0] = 0;
    tapCon(1);
    return 0;
}
