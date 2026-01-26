#include <iostream>

using namespace std;
int a[100];
int n;

int tongLe(int i) {
    if(i == n)
        return 0;
    if(a[i] %2 != 0)
        return a[i] + tongLe(i+1);
    return tongLe(i+1);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << tongLe(0);
    return 0;
}
