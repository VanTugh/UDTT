#include <iostream>
#include <vector>
using namespace std;

struct Laptop {
    string brand, config;
};

// khai báo hàm
int BMH(string text, string pat);
vector<int> Z(string s);

int main() {
    vector<Laptop> d = {
        {"HP", "CPU 2.5GHz RAM 16GB SSD 512GB"},
        {"ACER", "CPU 2.4GHz RAM 8GB HDD 1TB"},
        {"DELL", "CPU 3.0GHz RAM 16GB SSD 1TB"},
        {"ASUS", "CPU 2.8GHz RAM 8GB SSD 256GB"}
    };

    cout << "Laptop co RAM 16GB:\n";
    for (auto x : d) {
        if (BMH(x.config, "RAM 16GB") > 0)
            cout << x.brand << " - " << x.config << endl;
    }

    cout << "\nLaptop su dung SSD:\n";
    for (auto x : d) {
        string s = "SSD$" + x.config;
        vector<int> z = Z(s);
        bool found = false;
        for (int v : z)
            if (v == 3) found = true;
        if (found)
            cout << x.brand << " - " << x.config << endl;
    }
}
