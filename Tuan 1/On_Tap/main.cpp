#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;

void sort_all(vector<float>& a, int left,int mid ,int right)
{
    int i = left, j = mid+1;
    vector<float> temp;
    while(i<= mid && j <=right)
    {
        if(a[i]<a[j])
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
    for(int k =0 ;  k<temp.size(); k++)
    {
        a[left+k] = temp[k];
    }

}
void sap(vector<float>& a, int left,int right)
{
    if(left >=right)
        return ;
    int mid = (left + right) /2;
    sap(a,left,mid);
    sap(a,mid+1,right);
    sort_all(a,left,mid,right);

}
float tim_max(vector<float>& a, int left , int right)
{
        int mid = (left+right) /2;
        if(left == right)
            return a[left];
        float max_left= tim_max(a,left, mid);
        float max_right=tim_max(a,mid+1,right);
        if(max_left > max_right)
            return max_left;
        else
            return max_right;
}
float tong_cac_so_duong(vector<float>& a, int left , int right)
{
    if(left == right)
        return a[left] > 0 ? a[left] :0 ;
    float mid = (left+right)/2;
    float sum_left = tong_cac_so_duong(a,left,mid);
    float sum_right = tong_cac_so_duong(a,mid+1,right);
    return sum_left+sum_right;
 }
 void nhap_lieu(vector<int>& a ,int n)
{
    for(int i =0 ; i<n ; i++)
    {
        cout<<" nhap gia tri cho a["<<i+1<<"] = ";
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
int tim_so_chan(vector<int>& a, int left , int right)
{
    if(left == right)
        return a[left] % 2 == 0 ? a[left] : 0;
    int mid = (left+right) /2;
    int min_left = tim_so_chan(a,left,mid);
    int min_right = tim_so_chan(a,mid+1,right);
    if (min_left < min_right)
        return min_left;
    else
        return min_right;
}
int main()
{
//    int n = 15;
//    vector<float> a(n);
//    nhap_lieu(a,n);
//    inKQ(a,n);
//    sap(a,0,n-1);
//    cout<<" ket qua sau khi sap : "<<endl;
//    inKQ(a,n);
//    float ketQua = tim_max(a, 0, n - 1);
//    cout << "Gia tri lon nhat trong danh sach la: " << ketQua << endl;
//    float tong = tong_cac_so_duong(a,0, n-1);
//    cout<<tong;

    int n = 15;
    vector<int> a(n);
    nhap_lieu(a,n);
    inKQ(a,n);
    int ketqua = tim_so_chan(a,0, n-1);
    cout<<ketqua;
    return 0;
}
