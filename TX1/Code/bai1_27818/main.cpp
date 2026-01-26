#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void nhap_lieu(vector<float> &a ,int n)
{
    for(int i =0 ;i<n;i++)
    {
        cout<<" nhap a["<<i+1<<"] = ";
        cin>>a[i];
    }
}
void inKQ(vector<float>& a, int n)
{
    cout<<" DANH SACH "<<endl;
    for(int i =0 ; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int F1(vector<float> &a , int n , int i, float k, float &tong)
{
    if(i==n)
        return 0;
    int dem = F1(a,n,i+1,k,tong);
    if(fmod(a[i], k) == 0)
    {
        tong +=a[i];
        return dem +1;
    }
    return dem;
}

int main()
{
    int n;
     cout<<" nhap vao n ( n > =12 ): ";
    while (true)
    {
       cin>>n;
       if (n < 12)
        cout<<" nhap lai ! : ";
        else
            break;
    }
    float k;
    vector<float> a(n);
    nhap_lieu(a,n);
    cout<<" nhap gia tri cho k : ";
    cin>>k;

    inKQ(a,n);
    float tong = 0;
int dem = F1(a, n, 0, k, tong);

if (dem > 0)
    cout << "Tong = " << tong;
else
    cout << "Khong co so nao trong mang A chia het cho k";

    return 0;
}
