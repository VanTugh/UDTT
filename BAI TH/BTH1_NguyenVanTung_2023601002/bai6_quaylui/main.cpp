#include <iostream>
using namespace std;

int n = 6;
int a[10];
bool used[10] = {false};

string name[] = {
    "", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"
};
char ghe[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f'};

void xuat() {
    for (int i = 1; i <= n; i++)
        cout << ghe[i] << ": " << name[a[i]] << "  ";
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;

            if (i == n)
                xuat();
            else
                Try(i + 1);

            used[j] = false;
        }
    }
}

int main() {
    Try(1);
    return 0;
}
