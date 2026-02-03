#include <iostream>
#include <string>
using namespace std;

string congSoLon(string a, string b) {
    if (a.length() < b.length())
        swap(a, b);

    int carry = 0;
    string res = "";

    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res = char(sum % 10 + '0') + res;
        carry = sum / 10;
    }
    return res;
}

int main() {
    string m, n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Tong = " << congSoLon(m, n) << endl;
}
