#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int p = 0;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] == '0')
        {
            a[p] = 0;
            ++p;
        }
        if (s[i] == '1')
        {
            a[p] = 1;
            ++p;
        }
        if (s[i]=='2')
        {
            a[p] = 2;
            ++p;
        }
        if (s[i]=='3')
        {
            a[p] = 3;
            ++p;
        }
        if (s[i]=='4')
        {
            a[p] = 4;
            ++p;
        }
        if (s[i]=='5')
        {
            a[p] = 5;
            ++p;
        }
        if (s[i]=='6')
        {
            a[p] = 6;
            ++p;
        }
        if (s[i]=='7')
        {
            a[p] = 7;
            ++p;
        }
        if (s[i]=='8')
        {
            a[p] = 8;
            ++p;
        }
        if (s[i]=='9')
        {
            a[p] = 9;
            ++p;
        }
    }
    sort(a,a+p);
    for (int i = p-1;i >= 0;i--)
    {
        string b;
        b = to_string(a[i]);
        cout << b;
    }
    return 0;
}
