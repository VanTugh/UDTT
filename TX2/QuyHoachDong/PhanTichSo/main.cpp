#include <iostream>
using namespace std;
int n = 5, m = 3;
int a[100], k = 0;

void backtrack(int sum, int last)
{
    if (sum == n)
    {
        for (int i = 0; i < k; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }

    for (int i = last; i >= 1; i--)
    {
        if (sum + i <= n)
        {
            a[k++] = i;
            backtrack(sum + i, i);
            k--;
        }
    }
}
int main()
{
    int n = 5, m = 3;

    int dp[100][100] = {0};
    for(int j =0; j<=m ;j++)
    {
        dp[0][j] = 1;
    }
    for(int i =1; i<=n;i++)
    {
        for(int j =1; j<=m ;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(i>=j)
            {
                dp[i][j] +=dp[i-j][j];
            }
        }
    }
    cout << "So cach phan tich: " << dp[n][m] << endl;
    backtrack(0, m);
}
