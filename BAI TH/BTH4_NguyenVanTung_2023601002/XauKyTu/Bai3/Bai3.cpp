#include <iostream>
#include <string>
#include <vector>
using namespace std;

int BMH(string text, string pat) {
    int n = text.length(), m = pat.length();
    vector<int> shift(256, m);

    for (int i = 0; i < m - 1; i++)
        shift[pat[i]] = m - 1 - i;

    int count = 0;
    int i = 0;

    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == text[i + j])
            j--;
        if (j < 0) {
            count++;
            i += m;
        } else {
            i += shift[text[i + m - 1]];
        }
    }
    return count;
}

int main() {
    string s = "toi co 1000, Nam co 21000, Dong co 1000 va 500";
    string pat = "1000";

    int cnt = BMH(s, pat);
    cout << "So lan xuat hien '1000': " << cnt << endl;

    // Thay thế
    int pos = 0;
    while ((pos = s.find("1000", pos)) != string::npos) {
        s.replace(pos, 4, "mot nghin");
        pos += 9;
    }

    cout << "Xau sau khi thay:\n" << s << endl;
}
