#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    double weight;
    double volume;
    double ratio;
};
int main()
{
  int n;
    double k;

    cout << "Nhap so kien hang: ";
    cin >> n;

    cout << "Nhap dung tich thung xe: ";
    cin >> k;
    vector<Item> a(n);
    for (int i =0 ; i<n ;i++)
    {
        cout<<"nhap thong tin : "<<i+1<<endl;
        cin>>a[i].weight>>a[i].volume;
                a[i].ratio = a[i].weight / a[i].volume;
    }
    sort(a.begin(), a.end(),[](Item x, Item y)
         {
             return x.ratio>y.ratio;
         });
        double totalWeight = 0;
    double remaining = k;
     for (int i = 0; i < n && remaining > 0; i++) {
        if (a[i].volume <= remaining) {
            remaining -= a[i].volume;
            totalWeight += a[i].weight;
            cout << "- Lay toan bo kien ("
                 << a[i].weight << " kg, "
                 << a[i].volume << " m3)\n";
        }
    }

    cout << "\nTong khoi luong toi da: " << totalWeight << " kg\n";
    return 0;
}
