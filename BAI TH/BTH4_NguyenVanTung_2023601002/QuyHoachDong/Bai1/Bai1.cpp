#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 6;
    vector<int> w = {0, 2, 3, 4, 5, 9, 7}; // trọng lượng
    vector<int> v = {0, 3, 4, 5, 8, 10, 6}; // giá trị

    int m;
    cout << "Nhap suc chua toi da m: ";
    cin >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << "\nGia tri lon nhat: " << dp[n][m] << endl;

    // Truy vết
    int j = m;
    int count = 0;
    cout << "Cac goi da lay:\n";
    for (int i = n; i >= 1; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "Goi " << i << ": w=" << w[i] << ", v=" << v[i] << endl;
            j -= w[i];
            count++;
        }
    }
    cout << "Tong so goi: " << count << endl;
}
