#include<bits/stdc++.h>
using namespace std;

const int MAXs = 1e6+7;
string s;
int ans[MAXs], k;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans[++k] = s[i]-'0';
        }
    }
    sort(ans+1, ans+1+k, cmp);
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i];
    }

    return 0;
}
