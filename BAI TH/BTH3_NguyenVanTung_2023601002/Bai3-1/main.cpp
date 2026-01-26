#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct SinhVien
{
    string ten;
    string hoDem;
    int namSinh;
    string diaChi;
};
void nhap_lieu(vector<SinhVien>& sv , int n)
{
    cout<<" nhap vao danh sach sinh vien"<<endl;
    for(int i =0; i< n ;i++)
    {
        cout<<" nhap thong tin cho sinh vien thu "<<i+1<<endl;
        cout<<" nhap ten sinh vien : ";
        cin>>sv[i].ten;
        cout<<" nhap ho dem : ";
        cin>>sv[i].hoDem;
        cout<<" nhap nam sinh : ";
        cin>>sv[i].namSinh;
        cout<<" nhap dia chi: ";
        cin>>sv[i].diaChi;
    }
}
void inKQ(const vector<SinhVien>& sv, int n)
{
    cout<<" DANH SACH SINH VIEN "<<endl;
    cout<<left<<setw(15)<<"Ten sinh vien "
               <<setw(15)<<"Ho dem sinh vien "
               <<setw(15)<<"Nam sinh  "
               <<setw(15)<<"Dia chi sinh vien "<<endl;
    for(int i = 0 ;i<n;i++)
    {
        cout<<left<<setw(15)<<sv[i].ten
               <<setw(15)<<sv[i].hoDem
               <<setw(15)<<sv[i].namSinh
               <<setw(15)<<sv[i].diaChi<<endl;
    }
}
void mergee(vector<SinhVien>& a, int left , int mid , int right)
{
    int i = left;
    int j = mid +1;
    vector<SinhVien> temp;
    while(i <= mid && j <=right)
    {
        if(a[i].ten < a[j].ten)
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
void sort_merger(vector<SinhVien>& sv, int left , int right)
{
    int mid = (left+right) /2;
    if(left>=right)
        return;
    sort_merger(sv,left, mid);
    sort_merger(sv, mid+1, right);
    mergee(sv,left,mid,right);
}
int tim_kiem(string name, vector<SinhVien>& sv, int left, int right)
{
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(sv[mid].ten == name)
        return mid;
    else if(name < sv[mid].ten)
        return tim_kiem(name, sv, left, mid - 1);
    else
        return tim_kiem(name, sv, mid + 1, right);
}

int main()
{
    int n;
    cout<<" nhap vao so sinh vien : ";
    cin>>n;
    vector<SinhVien> sv(n);
    nhap_lieu(sv,n);
    inKQ(sv,n);

    sort_merger(sv,0,n-1);
    cout<<" ket qua sau khi sap "<<endl;
    inKQ(sv,n);

    string name;
    cout<<" nhap ten sinh vien can tim :";
    cin>>name;

    int i = tim_kiem(name,sv,0, n-1);
    cout<<left<<setw(15)<<sv[i].ten
               <<setw(15)<<sv[i].hoDem
               <<setw(15)<<sv[i].namSinh
               <<setw(15)<<sv[i].diaChi<<endl;
    return 0;
}
