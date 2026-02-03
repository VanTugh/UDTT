#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> mang = {1,3,4,5,6,7,8,9,6,5,5,7,8,8,65,12,34};
    int L[100] = {0};
    int n = mang.size();

    for (int i = 0; i < n; i++)
        L[i] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)   // QUAN TRỌNG
        {
            if (mang[i] > mang[j])
                L[i] = max(L[i], L[j] + 1);
        }
    }

    // In độ dài LIS
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, L[i]);

    cout << "Do dai LIS = " << ans;
}
