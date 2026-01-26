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
int sort_merge_TIM_MAX(vector<float>& a, int left , int right)
{
    if (left == right)
        return a[left];
    int mid = (left+right) /2;
    float max_left = sort_merge_TIM_MAX(a,left,mid);
    float max_right = sort_merge_TIM_MAX(a,mid+1, right);
    if (max_left > max_right)
        return max_left;
    else
        return max_right;

}
int main()
{
   int n = 15;
   vector <float> a(n);
   nhapLieu(a,n);
   inKQ(a,n);
   float ketQua = sort_merge_TIM_MAX(a, 0, n - 1);
   cout << "Gia tri lon nhat trong danh sach la: " << ketQua << endl;
   return 0;
}
