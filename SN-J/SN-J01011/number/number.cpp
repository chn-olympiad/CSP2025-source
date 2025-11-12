#include <bits/stdc++.h>
using namespace std;
long long int s[1000005];
long long int a[1000000];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    for (int i = 1; i <= 1000000; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= 1000000; i++)
    {
        if (s[i] == 0/ s[i] == 1/ s[i] == 2/ s[i] == 3/ s[i] == 4/ s[i] == 5/ s[i] == 6 s[i] == 7/ s[i] == 8/ s[i] == 9)
        {
            a[i] = s[i];
        }
    }
    sort (a + 1, a + 1000000 + 1, cmp);
    for (int i = 1; i <= 1000000; i++)
    {
        cout << a[i];
    }
    return 0;
}
