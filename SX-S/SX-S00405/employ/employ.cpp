#include <bits/stdc++.h>
using namespace std;
int n,m,ss[20],c[20],p[20],ans;
string s;
inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x = (x<<1)+(x<<3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n = read(); m = read(); cin >> s;
    for (int i = 1;i <= n;i++) p[i] = i;
    for (int i = 1;i <= n;i++) ss[i] = s[i-1]-'0';
    for (int i = 1;i <= n;i++) c[i] = read();
    do
    {
        int pst = 0,res = 0;
        // for (int i = 1;i <= n;i++) cout << p[i] << " \n"[i==n];
        for (int i = 1;i <= n;i++)
        {
            if (c[p[i]] <= pst)
            {
                pst++;continue;
            }
            if (ss[i] == 1)
            {
                res++;
            }
            else pst++;
        }
        if (res >= m) ans++;
        // cout << ans << "\n";
    }
    while(next_permutation(p+1,p+n+1));
    cout << ans;
    return 0;
}