#include <iostream>
using namespace std;

int xly_n()
{
    int n;
    while(true)
    {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n >= 0)
            break;
        cout << "Nhap lai, n >= 0\n";
    }
    return n;
}

double xu_ly(double a, int n)
{
    if(n == 0)
        return 1;

    double mid = xu_ly(a, n / 2);

    if(n % 2 == 0)
        return mid * mid;
    else
        return mid * mid * a;
}

int main()
{
    double a;
    cout << "Nhap so thuc a: ";
    cin >> a;

    int n = xly_n();
    double kq = xu_ly(a, n);

    cout << "a^n = " << kq << endl;
    return 0;
}
