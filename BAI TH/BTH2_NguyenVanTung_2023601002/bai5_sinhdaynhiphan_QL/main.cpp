#include <iostream>

using namespace std;
int n;
int a[100];
void sinh_nhi_phan(int i)
{
    for(int v =0 ; v<=1 ; v++)
    {
        a[i] = v;
        if (i == n)
        {
            for(int j = 0; j<=n; j++)
            cout<<a[j];
            cout<<endl;
        }
        else
        {
            sinh_nhi_phan(i+1);
        }

    }
}
int main()
{
    cin>>n;
    sinh_nhi_phan(1);
    return 0;
}
