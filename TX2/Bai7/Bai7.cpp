#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Workshop {
    string topic;
    int start, end;
};

int main(){
    vector<Workshop> w={
        {"CV",8,10},
        {"SoftSkill",9,11},
        {"AI",10,12},
        {"Startup",13,15},
        {"Interview",14,16}
    };

    sort(w.begin(), w.end(), [](Workshop a, Workshop b){
        return a.end < b.end;
    });

    int last=0, cnt=0;
    for(auto x:w){
        if(x.start>=last){
            cout<<x.topic<<" ("<<x.start<<"-"<<x.end<<")\n";
            last=x.end;
            cnt++;
        }
    }
    cout<<"Tong hoi thao: "<<cnt<<endl;
}
