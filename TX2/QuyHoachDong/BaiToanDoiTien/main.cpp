#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    // Các mệnh giá tiền
    vector<int> coin = {25, 10, 5, 1};

    int n;
    cout << "Nhap so tien: ";
    cin >> n;

    // dp[i] = số đồng tiền ít nhất để đổi i
    vector<int> dp(n + 1, INT_MAX);

    // Điều kiện cơ sở
    dp[0] = 0;

    // Quy hoạch động
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < coin.size(); j++)
        {
            if (coin[j] <= i && dp[i - coin[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    // Kết quả
    cout << "So dong tien it nhat: " << dp[n] << endl;

    return 0;
}
