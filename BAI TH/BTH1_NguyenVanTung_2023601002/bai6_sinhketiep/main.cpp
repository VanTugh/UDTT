#include <iostream>
using namespace std;

string name[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
bool ok = true;

void sinh() {
    int i = 4;
    while (i >= 0 && name[i] > name[i + 1])
        i--;

    if (i < 0) {
        ok = false;
        return;
    }

    int j = 5;
    while (name[j] < name[i])
        j--;

    swap(name[i], name[j]);

    int l = i + 1, r = 5;
    while (l < r) {
        swap(name[l], name[r]);
        l++;
        r--;
    }
}

int main() {
    while (ok) {
        for (int i = 0; i < 6; i++)
            cout << name[i] << " ";
        cout << endl;
        sinh();
    }
    return 0;
}
