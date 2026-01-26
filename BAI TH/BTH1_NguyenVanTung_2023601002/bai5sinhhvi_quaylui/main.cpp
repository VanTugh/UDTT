#include <iostream>
using namespace std;

int n, k;
int a[100];
bool used[100];
void tapCon(int i) {

    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;
            if (i == n) {
                for (int k = 1; k <= n; k++)
                    cout << a[k] << " ";
                cout << endl;
            } else {
                tapCon(i + 1);
            }
            used[j] = false;
        }
    }


}

int main() {
    cin >> n ;
    a[0] = 0;
    tapCon(1);
    return 0;
}
