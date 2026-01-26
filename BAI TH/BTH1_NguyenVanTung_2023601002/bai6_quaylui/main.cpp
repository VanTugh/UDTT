#include <iostream>

using namespace std;
#include <iostream>
using namespace std;

string name[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
bool used[6];
string seat[6];
void xepGhe(int i) {
    for(int j =0 ; j< 6;j++)
    {
    if(!used[j])
    {
        seat[i] = name[j];
        used[j] = true;
        if (i == 5) {
                for (int k = 0; k <6; k++)
                    cout << seat[k] << " ";
                cout << endl;
            } else {
                xepGhe(i + 1);
            }
            used[j] = false;
        }
    }
    }

int main() {
    xepGhe(0);
    return 0;
}
