#include <bits/stdc++.h>
using namespace std;
// phuonp phap:
//     khoi tao cau hinh dau tien
//     while(cau hinh cauoi cung)
//     {
//         in ra cau hinh hien tai
//         sinh ra cau hinh tiep theo
//     }
int n,k, a[100], ok;
void khoitao()
{
    for(int i= 0 ;i<=n ;i++)
    {
       a[i] = 0;
    }
}
void sinh(){
    int i = n;
    while(i>= 1 && a[i] ==1)
    {
        a[i] = 0;
        i =i-1;
    }
    if (i==0)
    {
        ok = 0; //cau hinh cuoi cung
    }
 else
 {
     a[i] = 1;
 }
 }
 // mo rong : neu de la sinh sau nhi phan co k bit 1
 bool check()
 {
     int count =0;
     for ( int i= 0;i<=n;i++)
     {
         count+=a[i];
     }
     return count == k;
 }
int main()
{
    cin>>n, k;
    ok = 1;
    khoitao();
    while(ok)
    {
//        if (check()) : check roi moi in

        // in ra cau hinh hien tai
        for(int i =0 ; i<= n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        sinh();
    }
    int kq = check();
}
