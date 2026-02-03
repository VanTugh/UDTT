#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> a = {2.1, 3.5, 1.2, 4.6, 2.8, 5.9, 3.1, 6.0, 7.2,
                         4.0, 8.3, 5.1, 9.4, 6.2, 10.0};
    int n = a.size();

    vector<int> dp(n, 1), trace(n, -1);

    int best = 0, pos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if (dp[i] > best) {
            best = dp[i];
            pos = i;
        }
    }

    cout << "Do dai LIS: " << best << endl;
    cout << "Day con: ";

    vector<double> lis;
    while (pos != -1) {
        lis.push_back(a[pos]);
        pos = trace[pos];
    }

    for (int i = lis.size() - 1; i >= 0; i--)
        cout << lis[i] << " ";
}
