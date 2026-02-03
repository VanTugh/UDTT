#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 6;
    vector<int> w = {0, 2, 3, 4, 5, 9, 7};
    vector<int> v = {0, 3, 4, 5, 8, 10, 7};

    int m;
    cout << "Nhap suc chua toi da cua tui: ";
    cin >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i =1 ; i<=n;i++)
    {
        for(int j =0 ; j<=m ; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >=w[i] )
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] +v[i]);
            }
        }
    }
    cout<<" lay duoc gia tri max : "<<dp[n][m]<<endl;
    cout << "\nCac goi hang duoc chon:\n";
    int j = m;
    int count = 0;

    for (int i = n; i >= 1; i--)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            cout << "Goi " << i
                 << " | Trong luong: " << w[i]
                 << " | Gia tri: " << v[i] << endl;
            j -= w[i];
            count++;
        }
    }
}
