#include <iostream>

using namespace std;
int n , ok ,k, a[100];

void khoitao()
{
    for( int  i = 1 ; i<=k ; i++)
    {
        a[i] = i;
    }
}
void sinh_k_tu_n()
{
    int i = k;
    while( i >= 1 && a[i]== n - k+i)
    {
        i--;
    }
    if( i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i]++;
        for(int j = i +1 ; j<= k ; j++)
        {
            a[j] = a[j-1] +1;
        }
    }
}
int main()
{
    cout<<" hay nhap n : "<<endl;
    cin >>n;
    cout<<" hay nhap k : "<<endl;
    cin >>k;
    ok = 1;
    khoitao();
    while(ok)
    {
        for (int  i =1 ; i<=k ;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        sinh_k_tu_n();
    }
    return 0;
}
