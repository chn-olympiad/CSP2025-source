#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a = []
    cin >> s;
    for (int i = 1,i<=s.length();i++)
    {
        if (i > 0 && i < 10)
        {
            a[i] = 1;
        }
    }
    sort(a);
    for (int i = 1,i <= a.length();i++)
    {
        cout << a[i];
    }
}
