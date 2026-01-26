#include <iostream>
using namespace std;

int a[100][100];
int visited[100][100];
int n, m;

void loang(int i, int j) {
    visited[i][j] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        int i_moi = i + dx[k];
        int j_moi = j + dy[k];
        if (i_moi >= 1 && i_moi <= n && j_moi >= 1 && j_moi <= m
            && a[i_moi][j_moi] == 1 && visited[i_moi][j_moi] == 0) {
            loang(i_moi, j_moi);
        }
    }
}
int main() {
    cout << "Nhap so dong n, so cot m: "; cin >> n >> m;
    cout << "Nhap ma tran (0 hoac 1):\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
            visited[i][j] = 0;
        }
    }
    int dem = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if (a[i][j] == 1 && visited[i][j] == 0) {
                dem++;
                loang(i, j);
            }
        }
    }
    cout << "So mien lien thong: " << dem;
    return 0;
}
