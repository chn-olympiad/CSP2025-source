#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s = [];
    int n,m;
    x = s[0];
    for (int i= 0;i < s.length();i++)
    {
        cin >> a[i];
    }
    sort(a);
    for (int i = 1;i <= a.length();i++)
    {
        if (a[i] == x)
        {
            f = i;
        }
    }
    if (f % n == 0)
    {
        if ((f / n)% 2 == 0)
        {
            a = f / n;
            cout << a <<" " << 1;
        }
        else
        {
            a = f / n;
            cout << a << " " << n;
        }
    }
    if (f % n !=0)
    {
        if ((f / n) + 1) % 2 == 0)
        {
            a = n -  (f % n)+1;
            cout << a <<" " <<(f / n)+1;
        }
        else
        {
            cout << (f % n) <<" " << (f / n)+1;
        }
    }
}
