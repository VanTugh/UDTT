
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void nhap_lieu(vector<int> &a ,int n)
{
    for(int i =0 ; i<n ;i++)
    {
        cout<<" nhap a["<<i+1<<"] = ";
        cin>>a[i];
    }
}
void inKQ(vector<int>& a, int n)
{
    cout<<" DANH SACH "<<endl;
    for(int i =0 ; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
bool check(int a, int b)
{
    return pow(a,b) > pow(b,a);
}
void sinh_A_B(int n, int m , vector<int>& a, vector<int> &b)
{
    bool found = false;
    for(int i = 0 ; i <n ;i++)
    {
        for(int j= 0 ; j<m;j++)
        {
            if(check(a[i] , b[j]))
            {
                cout<<a[i]<<b[j]<<endl;
                found = true;
            }
        }
    }
    if(!found)
    {
        cout<<" khong co cap nao"<<endl;
    }
}
void nhap_lieu_b2(vector<float>& a, int n)
{
    for(int i =0 ; i<n ;i++)
    {
        cout<<" nhap a["<<i+1<<"] = ";
        cin>>a[i];
    }
}
void inKQb2(vector<float>& a, int n)
{
    cout<<" DANH SACH "<<endl;
    for(int i =0 ; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
bool check_so_le(float n)
{
    int phan_nguyen = (int)n;
    if(n==phan_nguyen && phan_nguyen % 2 !=0 )
        return true;
    return false;
}
float tinh_tong_sle(vector<float>&a, int index)
{
    if(index == a.size())
        return 0;
    float giatrihientai = 0;
    if(check_so_le(a[index]))
        giatrihientai +=a[index];
    return giatrihientai + tinh_tong_sle(a,index+1);
}
int dem_k(vector<float> &a , int left,int right, int k)
{
    if (left == right)
        return a[left] <= k ? 1 : 0;
    int mid = (left+right) / 2;
    int dem_trai= dem_k(a,left,mid,k);
    int dem_phai = dem_k(a,mid+1,right,k);
    return dem_trai+dem_phai;
}
int main()
{
//    int n,m;
//    cout<<" nhap n = "; cin>>n;
//    cout<<" nhap m = "; cin>>m;
//   vector<int >a(n);
//   vector<int> b(m);
//   cout<<" nhap cho a"<<endl;
//   nhap_lieu(a,n);
//   inKQ(a,n);
//   cout<<endl;
//    cout<<" nhap cho b"<<endl;
//   nhap_lieu(b,m);
//   inKQ(b,m);
//   sinh_A_B(n,m,a,b);

int n;
cout<<" nhap n : ";
while (true)
{
    cin>>n;
    if (n <10)
            cout<<" nhap lai : ";
    else
        break;
}
float k;
cout<<" nhap vao k : ";
cin>>k;

vector<float> a(n);
nhap_lieu_b2(a,n);
inKQb2(a,n);
cout<<endl;
float tong = tinh_tong_sle(a,0);
cout<<" tong = "<<tong<<endl;
int dem = dem_k(a,0,n-1,k);
cout<<" co : "<<dem<<" so le lon hon "<<k<<endl;
    return 0;
}
