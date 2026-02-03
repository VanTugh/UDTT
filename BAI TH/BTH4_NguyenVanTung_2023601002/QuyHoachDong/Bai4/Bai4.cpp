#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n = 4;
    vector<int> c = {1, 3, 5, 10};

    int m;
    cout << "Nhap so tien m: ";
    cin >> m;

    vector<int> f(m + 1, INF), s(m + 1, -1);
    f[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j] && f[i - c[j]] + 1 < f[i]) {
                f[i] = f[i - c[j]] + 1;
                s[i] = c[j];
            }
        }
    }

    cout << "So to it nhat: " << f[m] << endl;
    cout << "Cac menh gia: ";

    int i = m;
    while (i > 0) {
        cout << s[i] << " ";
        i -= s[i];
    }
}
