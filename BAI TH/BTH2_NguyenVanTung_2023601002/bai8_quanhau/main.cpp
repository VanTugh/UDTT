#include <iostream>
#include <cmath> 

using namespace std;

int n;          
int H[100];    

void XuatKetQua() {
    static int count = 0;
    count++;
    cout << "Cach xep thu " << count << ": ";
    for (int i = 1; i <= n; i++) {
        // In ra vị trí cột của hậu ở từng hàng
        cout << "(" << i << "," << H[i] << ") ";
    }
    cout << endl;

    // Vẽ bàn cờ minh họa (tùy chọn)
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (H[i] == j) cout << " H ";
            else cout << " . ";
        }
        cout << endl;
    }
    cout << "----------------\n";
}

// Hàm kiểm tra ô (k, i) có an toàn không
// k: hàng đang xét, i: cột đang định đặt
bool KiemTraAnToan(int k, int i) {
    // Kiểm tra với các quân hậu đã đặt ở các hàng trước (từ 1 đến k-1)
    for (int j = 1; j < k; j++) {
        // H[j] là cột của hậu ở hàng j

        // 1. Kiểm tra trùng cột: H[j] == i
        // 2. Kiểm tra trùng đường chéo: |k - j| == |i - H[j]|
        if (H[j] == i || abs(k - j) == abs(i - H[j])) {
            return false; // Không an toàn
        }
    }
    return true; // An toàn
}

// Hàm quay lui tìm vị trí đặt hậu thứ k
void Try(int k) {
    // Duyệt toàn bộ n vị trí ứng cử (các cột) của hàng k
    for (int i = 1; i <= n; i++) {
        // Kiểm tra xem vị trí (k, i) có an toàn không
        if (KiemTraAnToan(k, i)) {
            // Nếu an toàn, ghi nhớ vị trí: Hàng k đặt ở cột i
            H[k] = i;

            // Kiểm tra điều kiện dừng
            if (k == n) {
                XuatKetQua(); // Đã đặt đủ n hậu
            } else {
                // Tìm tiếp vị trí cho hậu ở hàng k + 1
                Try(k + 1);
            }

            // Quay lui: Với mảng 1 chiều, ta không cần lệnh xóa từ minh
            // vì giá trị H[k] sẽ tự động bị ghi đè ở vòng lặp tiếp theo.
        }
    }
}

int main() {
    cout << "Nhap kich thuoc ban co (VD: 8): ";
    cin >> n;

    cout << "Cac phuong an xep hau la: " << endl;
    Try(1); // Bắt đầu tìm vị trí cho hậu ở hàng 1

    return 0;
}
