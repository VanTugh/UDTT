#include <iostream>
#include <stack>
using namespace std;

// Cấu trúc để lưu trạng thái của một lần gọi hàm
struct Call {
    int n;
    char a, b, c; // Nguồn, Trung gian, Đích
};

void ThapHaNoi_KhuDeQuy(int n, char a, char b, char c) {
    stack<Call> s;
    // Đẩy trạng thái ban đầu vào stack
    s.push({n, a, b, c});

    while (!s.empty()) {
        Call top = s.top();
        s.pop();

        if (top.n == 1) {
            cout << "Chuyen 1 dia tu " << top.a << " sang " << top.c << endl;
        } else {
            // Thứ tự thực hiện mong muốn:
            // 1. (n-1) A -> B
            // 2. (1)   A -> C
            // 3. (n-1) B -> C
            // Do Stack là LIFO nên ta Push theo thứ tự ngược lại: 3 -> 2 -> 1

            // 3. Chuyen n-1 tu B sang C
            s.push({top.n - 1, top.b, top.a, top.c});

            // 2. Chuyen 1 tu A sang C (đĩa to nhất)
            s.push({1, top.a, top.b, top.c});

            // 1. Chuyen n-1 tu A sang B
            s.push({top.n - 1, top.a, top.c, top.b});
        }
    }
}

int main() {
    int n;
    cout << "Nhap so dia: "; cin >> n;
    ThapHaNoi_KhuDeQuy(n, 'A', 'B', 'C');
    return 0;
}
