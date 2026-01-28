#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int n;
int H[20][20];
int a[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int b[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void XuatKetQua()
{
    cout << "Tim thay duong di:" << endl;
    for(int i = 1; i <=n ;i++)
    {
        for(int j =1; j<=n ;j++)
        {
            cout<<H[i][j]<<" ";
        }
        cout<<endl;
    }
    exit(0);
}
void Try(int k ,int x, int y)
{
    for(int i =0 ; i<8 ;i++)
    {
        int u = x + a[i];
        int v = y + b[i];
        if (u >= 1 && u <= n &&
            v >= 1 && v <= n && H[u][v] == 0)
        {
            H[u][v] = k;
            if(k == n*n)
            {
                XuatKetQua();
            }
            else
            {
                Try(k+1,u,v);
            }
            H[u][v] = 0;
        }
    }
}
int main() {
    int x, y;
    cin >> n;
    cin >> x >> y;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            H[i][j] = 0;

    H[x][y] = 1;
    Try(2, x, y);

    cout << "Khong tim thay loi giai";
    return 0;
}
