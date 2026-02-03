#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so xe: ";
    cin >> n;

    vector<int> k(n);
    cout << "Nhap tai trong cac xe:\n";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    cout << "Nhap so tan hang can chuyen: ";
    cin >> m;
    sort(k.begin(), k.end(), greater<int>());
    int soXe =0 ;
    vector<int> xeDuocChon;
    for(int i = 0; i< n  && m >0; i++ )
    {
        xeDuocChon.push_back(k[i]);
        m-=k[i];
        soXe++;
    }
     if (m > 0) {
        cout << "Khong du xe de chuyen het hang!\n";
    } else {
        cout << "So xe can dung it nhat: " << soXe << endl;
        cout << "Cac xe duoc chon (tai trong): ";
        for (int x : xeDuocChon)
            cout << x << " ";
    }

    return 0;

}
