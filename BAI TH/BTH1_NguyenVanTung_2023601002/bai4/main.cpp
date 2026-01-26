#include <iostream>
using namespace std;

string name[7] = {"", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
int a[5];

void chonSV(int i) {
    for (int j = a[i - 1] + 1; j <= 6; j++) {
        a[i] = j;
        if (i == 4) {
            for (int k = 1; k <= 4; k++)
                cout << name[a[k]] << " ";
            cout << endl;
        } else {
            chonSV(i + 1);
        }
    }
}

int main() {
    a[0] = 0;
    chonSV(1);
    return 0;
}
