#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BMH(string t, string p) {
    int n=t.size(), m=p.size(), cnt=0;
    vector<int> shift(256,m);
    for(int i=0;i<m-1;i++) shift[p[i]]=m-1-i;
    int i=0;
    while(i<=n-m){
        int j=m-1;
        while(j>=0 && p[j]==t[i+j]) j--;
        if(j<0){ cnt++; i+=m; }
        else i+=shift[t[i+m-1]];
    }
    return cnt;
}
