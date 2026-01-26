#include <iostream>

using namespace std;
int n , ok , a[100];

void khoitao()
{
    for( int  i = 1 ; i<= n ; i++)
    {
        a[i] = 0;
    }
}
void sinhhoanvi()
{
    int i = n;
    while( i >= 1 && a[i]== 1)
    {
        a[i] = 0;
        i--;
    }
    if( i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i] = 1;
    }
}
int main()
{
    cout<<" hay nhap n : "<<endl;
    cin >>n;
    ok = 1;
    khoitao();
    while(ok)
    {
        for (int  i =1 ; i<= n ;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        sinhhoanvi();
    }
    return 0;
}
