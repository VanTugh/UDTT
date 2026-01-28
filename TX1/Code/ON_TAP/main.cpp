#include <iostream>

using namespace std;
int n, k;
int a[100];
bool used[100];
void khoitao()
{
    for( int  i = 1 ; i<=n ; i++)
    {
        a[i] = i;
    }
}
void tapcon(int i)
{
    for(int j = 1; j<= n ; j++)
    {
        if(!used[j])
        {
            a[i] = j;
            used[j] = true;
            if(i == n)
            {
                for(int v =1 ; v<= n; v++ )
                    cout<<a[v];
                cout<<endl;
            }
            else
            {
                tapcon(i+1);
            }
            used[j] = false;
        }
    }
}

int main() {
    cin >> n ;
    a[0] = 0;
    tapcon(1);
    return 0;
}
