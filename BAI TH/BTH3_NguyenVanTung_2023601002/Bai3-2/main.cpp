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
void sort_mergee(vector<float>& a, int left, int mid, int right)
{
    int i = left;
    int j = mid +1;
    vector<float> temp;
    while(i <= mid && j <=right)
    {
        if(a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(a[i]);
            i++;
    }
     while(j<=right)
    {
        temp.push_back(a[j]);
            j++;
    }

    for(int k =0 ;k <temp.size() ;k++)
    {
        a[k+left] = temp[k];
    }
}
void sort_merger(vector<float>& a, int left , int right)
{
    int mid = (left+right) /2;
    if(left>=right)
        return;
    sort_merger(a,left, mid);
    sort_merger(a, mid+1, right);
    sort_mergee(a,left,mid,right);
}
int main()
{
   int n = 15;
   vector <float> a(n);
   nhapLieu(a,n);
   inKQ(a,n);
   sort_merger(a,0,n-1);
   cout<<" ket qua sau khi sap : "<<endl;
   inKQ(a,n);
}
