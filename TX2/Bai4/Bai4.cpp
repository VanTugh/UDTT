#include <iostream>
#include <vector>
using namespace std;

struct Phone {
    string brand;
    int size;
    int price;
};

int main() {
    int s = 15;
    vector<Phone> d = {
        {"Samsung",6,500},
        {"Apple",6,800},
        {"Xiaomi",7,450},
        {"Oppo",6,400},
        {"Nokia",5,300}
    };

    int n = d.size();
    vector<vector<int>> dp(n+1, vector<int>(s+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=d[i-1].size)
                dp[i][j] = max(dp[i][j],
                    dp[i-1][j-d[i-1].size] + d[i-1].price);
        }
    }

    cout<<"Tong gia lon nhat: "<<dp[n][s]<<endl;
    int j=s;
    for(int i=n;i>=1;i--){
        if(dp[i][j]!=dp[i-1][j]){
            cout<<d[i-1].brand<<" - "<<d[i-1].price<<endl;
            j-=d[i-1].size;
        }
    }
}
