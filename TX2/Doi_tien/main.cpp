#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a = {25, 10, 5, 1};

int n;
void sap()
{
    sort(a.begin(), a.end(), greater<int>());
}
void doiTien()
{
   for(int i =0 ; i< a.size(); i++)
   {
       while(a[i] <= n)
       {
           cout<<" lay "<<a[i]<<" ";
           n-=a[i];
       }
   }
}
int main()
{
   cout<<" nhap tien = ";
   cin>>n;
   sap();
   doiTien();
    return 0;
}
