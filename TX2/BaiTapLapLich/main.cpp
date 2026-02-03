#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};
int countt;
int last;
vector<Activity> a = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };
void sap()
{
    sort(a.begin(), a.end(),
        [](Activity x, Activity y) {
             return x.finish < y.finish;
         });
}
void in()
{
    for( int i = 0; i<a.size();i++)
    {
        cout<<a[i].start<<" : "<<a[i].finish<<endl;
    }
}
void lapLich()
{
countt =1;
last = a[0].finish;
for(int i =1 ;i<a.size();i++)
{
    if(a[i].start >= last)
    {
        countt++;
        last = a[i].finish;
    }
}
 cout << "So hoat dong toi da: " << countt << endl;
}
int main()
{
    sap();
    in();
    lapLich();
}
