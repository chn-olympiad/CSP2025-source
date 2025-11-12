#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string ans[1005];
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
        if ('0' <= s[i] && s[i] <= '9')
            cout << s[i];
    return 0;
}
