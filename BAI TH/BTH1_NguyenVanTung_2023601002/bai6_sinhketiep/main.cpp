#include <iostream>
using namespace std;

int n = 6;
int a[10];
bool ok = true;

string name[] = {
    "", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"
};
char ghe[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f'};

void khoitao() {
    for (int i = 1; i <= n; i++)
        a[i] = i;
}

void sinh() {
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
        i--;

    if (i == 0)
        ok = false;
    else {
        int j = n;
        while (a[j] < a[i])
            j--;

        swap(a[i], a[j]);

        int l = i + 1, r = n;
        while (l < r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }
}

void xuat() {
    for (int i = 1; i <= n; i++)
        cout << ghe[i] << ": " << name[a[i]] << "  ";
    cout << endl;
}

int main() {
    khoitao();
    while (ok) {
        xuat();
        sinh();
    }
    return 0;
}
