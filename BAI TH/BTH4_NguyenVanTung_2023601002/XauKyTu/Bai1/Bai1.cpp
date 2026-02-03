#include <iostream>
#include <string>
using namespace std;

bool laDoiXung(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

string doiXungTam(string s, int k) {
    int l = k, r = k;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--; r++;
    }
    return s.substr(l + 1, r - l - 1);
}

int main() {
    string s = "abacdfgdcaba";
    cout << "Xau: " << s << endl;

    if (laDoiXung(s)) {
        cout << "Xau la doi xung\n";
    } else {
        cout << "Xau khong doi xung\n";
        int k;
        cout << "Nhap vi tri k: ";
        cin >> k;
        cout << "Xau doi xung dai nhat co tam tai s[" << k << "]: ";
        cout << doiXungTam(s, k) << endl;
    }
}
