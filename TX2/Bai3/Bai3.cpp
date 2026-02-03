#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fan {
    string hang, mau;
    int gia;
};

int main() {
    int p = 500000;
    vector<Fan> d = {
        {"Panasonic","Trang",300000},
        {"Senko","Do",200000},
        {"Asia","Xanh",150000},
        {"Midea","Trang",100000},
        {"Sharp","Den",250000},
        {"Toshiba","Xam",180000}
    };

    // Bán quạt đắt nhất trước
    sort(d.begin(), d.end(), [](Fan a, Fan b) {
        return a.gia > b.gia;
    });

    int sum = 0;
    vector<Fan> ban;

    for (auto f : d) {
        sum += f.gia;
        ban.push_back(f);
        if (sum > p) break;
    }

    cout << "Ban it quat nhat de tong > p:\n";
    for (auto f : ban)
        cout << f.hang << " - " << f.gia << endl;

    cout << "Tong tien: " << sum << endl;
    cout << "So quat: " << ban.size() << endl;
}
