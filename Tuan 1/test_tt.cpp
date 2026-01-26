#include <iostream>
#include <cmath>
using namespace std;

int n;
int H[100];
int count = 0;

void vebanco()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(H[i] == j)
                cout << " H ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << "----------------\n";
}

void xuatKQ()
{
    count++;
    cout << "Cach xep thu " << count << endl;
    for(int i = 1; i <= n; i++)
        cout << "(" << i << "," << H[i] << ") ";
    cout << endl;
    vebanco();
}

bool kiemTraAnToan(int i, int k)
{
    for(int j = 1; j < k; j++)
    {
        if (H[j] == i || abs(k - j) == abs(H[j] - i))
            return false;
    }
    return true;
}

void trY(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(kiemTraAnToan(i, k))
        {
            H[k] = i;
            if(k == n)
                xuatKQ();
            else
                trY(k + 1);
        }
    }
}

int main()
{
    cout << "Nhap kich thuoc ban co: ";
    cin >> n;
    trY(1);
    return 0;
}
