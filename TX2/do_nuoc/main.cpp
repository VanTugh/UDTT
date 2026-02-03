#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a = {5,7,10,4,8};
int n;
void sap()
{
    sort(a.begin(), a.end());
}
void in()
{
    for( int i = 0; i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
void doNuoc()
{
    for(int i = 0 ;i<a.size();i++)
    {
        if (a[i]<=n)
        {
              cout<<" lay "<<a[i]<<" ";
           n-=a[i];
        }
    }
}
int main()
{
   cout<<" nhap n : ";
   cin>>n;
   sap();
   in();
   doNuoc();

    return 0;
}
