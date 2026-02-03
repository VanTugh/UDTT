#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Z(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string text = "apple banana apple orange apple banana";
    string first = text.substr(0, text.find(' '));

    string s = first + "$" + text;
    vector<int> z = Z(s);

    int count = 0;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == first.length())
            count++;
    }

    cout << "Tu dau tien '" << first << "' xuat hien: " << count << " lan\n";
}
