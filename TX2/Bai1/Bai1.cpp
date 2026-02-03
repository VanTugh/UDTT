#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fan {
    string hang, mau;
    int gia;
};

int main() {
    int p = 800000;
    vector<Fan> d = {
        {"Panasonic","Trang",150000},
        {"Senko","Do",120000},
        {"Asia","Xanh",180000},
        {"Midea","Trang",200000},
        {"Sharp","Den",250000},
        {"Toshiba","Xam",300000}
    };

    sort(d.begin(), d.end(), [](Fan a, Fan b) {
        return a.gia < b.gia;
    });

    int sum = 0, count = 0;
    cout << "Cac quat mua duoc:\n";
    for (auto f : d) {
        if (sum + f.gia <= p) {
            sum += f.gia;
            count++;
            cout << f.hang << " - " << f.gia << endl;
        }
    }

    cout << "Tong so quat: " << count << endl;
}
