#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void nhapLieu(vector<int>& a, int n)
{
    cout<<"Nhap danh sach : "<<endl;
    for(int i =0 ;i<n;i++)
    {
        cout<<" a["<<i+1<<"] = ";
        cin>>a[i];
    }
}
void inKQ(vector<int>& a, int n)
{
    cout<<"DANH SACH :"<<endl;
    for(int i =0 ;i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

float xu_ly(vector<int>& a, int left , int right)
{
    if ( left == right )
        return a[left] % 2 == 0 ? a[left] : 0;
    int mid = (right + left )/2;
    float min_left = xu_ly(a, left, mid);
    float min_right = xu_ly(a, mid +1 , right);
    if (min_left < min_right)
        return min_left;
    else
        return min_right;
}

int main()
{
    int n = 20;
   vector <int> a(n);
   nhapLieu(a,n);
   inKQ(a,n);
   float min_index = xu_ly(a,0, n-1);
   cout<<min_index;
}
