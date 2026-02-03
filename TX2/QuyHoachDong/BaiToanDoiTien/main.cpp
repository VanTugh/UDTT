#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 4;                 // số loại tiền
    int c[5] = {0, 25, 10, 5, 1}; // mệnh giá (bỏ c[0] cho dễ theo chỉ số)

    int m;
    cout << "Nhap so tien can doi: ";
    cin >> m;

    int f[1000];   // f[i]: số tờ tiền ít nhất để đổi i
    int s[1000];   // s[i]: loại tiền dùng cuối cùng để tạo ra i

    // Khởi tạo
    f[0] = 0;
    s[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        f[i] = INT_MAX;
        s[i] = 0;
    }

    // Quy hoạch động
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[j] <= i && f[i - c[j]] != INT_MAX)
            {
                if (f[i - c[j]] + 1 < f[i])
                {
                    f[i] = f[i - c[j]] + 1;
                    s[i] = j;
                }
            }
        }
    }

    // In kết quả
    cout << "\nSo to tien it nhat: " << f[m] << endl;
    cout << "Cac menh gia duoc su dung: ";

    int i = m;
    while (i > 0)
    {
        int j = s[i];
        cout << c[j] << " ";
        i = i - c[j];
    }

    return 0;
}
