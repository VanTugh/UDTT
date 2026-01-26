#include <iostream>

using namespace std;
int n , k;
int a[100];
bool used[100];
void sinhhoanvi(int i)
{
    for(int j =1 ; j<=n ;j++)
    {
        if(!used[j])
        {
            a[i] = j;
            used[j] = true;
            if( i == n)
            {
                for(int v =  1; v<= k ;v++)
                    cout<<a[v];
                cout<<endl;
            }
            else
            {
                sinhhoanvi(i+1);
            }
            used[j] = false;
        }

    }
}
int main()
{
    cin >>n >> k;
    sinhhoanvi(1);
    return 0;
}
