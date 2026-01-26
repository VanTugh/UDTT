#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void nhapLieu(vector<float>& a, int n)
{
    cout<<"Nhap danh sach : "<<endl;
    for(int i =0 ;i<n;i++)
    {
        cout<<" a["<<i+1<<"] = ";
        cin>>a[i];
    }
}
void inKQ(vector<float>& a, int n)
{
    cout<<"DANH SACH :"<<endl;
    for(int i =0 ;i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

float xu_ly(vector<float>& a, int left , int right)
{
    if ( left == right )
        return a[left] > 0 ? a[left] : 0;
    int mid = (right + left )/2;
    float sum_left = xu_ly(a, left, mid);
    float sum_right = xu_ly(a, mid +1 , right);
    return sum_left + sum_right;
}

int main()
{
    int n = 20;
   vector <float> a(n);
   nhapLieu(a,n);
   inKQ(a,n);
     
}
