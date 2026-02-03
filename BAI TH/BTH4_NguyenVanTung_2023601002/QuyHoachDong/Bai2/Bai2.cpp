#include <iostream>
using namespace std;

int n, m;
int x[100];

void quay_lui(int k, int sum) {
    if (sum == n) {
        for (int i = 1; i <= k; i++) cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = x[k - 1]; i <= m; i++) {
        if (sum + i <= n) {
            x[k] = i;
            quay_lui(k + 1, sum + i);
        }
    }
}

int main() {
    cout << "Nhap n, m: ";
    cin >> n >> m;

    int dp[100][100] = {0};

    for (int j = 0; j <= m; j++) dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= j)
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    cout << "So cach: " << dp[n][m] << endl;
    cout << "Cac cau hinh:\n";

    x[0] = 1;
    quay_lui(1, 0);
}
