#include <iostream>
#include <iomanip> 
#include <cstdlib>

using namespace std;

int n;
int H[20][20];
int a[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int b[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void XuatKetQua() {
    cout << "Tim thay duong di:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3) << H[i][j] << " ";
        }
        cout << endl;
    }
    exit(0);
}
void Try(int k, int x, int y) {
    
    for (int i = 0; i < 8; i++) {
        
        int u = x + a[i];
        int v = y + b[i];
        if (u >= 1 && u <= n && v >= 1 && v <= n && H[u][v] == 0) {

            // Ghi nhớ việc chọn nước đi
            H[u][v] = k;

            // Kiểm tra điều kiện dừng
            if (k == n * n) {
                XuatKetQua(); // Đã đi kín bàn cờ -> Xuất kết quả
            } else {
                // Tìm tiếp vị trí ở bước k + 1
                Try(k + 1, u, v);
            }

            // Quay lui (Backtracking): Xóa ghi nhớ nếu đường này không thành công
            H[u][v] = 0;
        }
    }
}

int main() {
    cout << "Nhap kich thuoc ban co n: ";
    cin >> n;

    int x_start, y_start;
    cout << "Nhap vi tri xuat phat (dong cot): ";
    cin >> x_start >> y_start;

    // Khởi tạo bàn cờ bằng 0
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            H[i][j] = 0;

    // Đặt bước đầu tiên tại vị trí xuất phát
    H[x_start][y_start] = 1;

    // Bắt đầu tìm bước thứ 2
    Try(2, x_start, y_start);

    cout << "Khong tim thay duong di.";
    return 0;
}
