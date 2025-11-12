#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, q;
int read()
{
    int x = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return x;
}
struct node
{
    string s, t;
}a[N + 5];
vector<int> p[N + 5];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = read(), q =read();
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].t;
        a[i].s = '+' + a[i].s, a[i].t = '+' + a[i].t;
        p[i].push_back(0);
        p[i].push_back(0);
        int l = a[i].s.length() - 1;
        int k = 0;
        for(int j = 2; j <= l; j++)
        {
            while(k > 0 && a[i].s[k + 1] != a[i].s[j]) k = p[i][k];
            if(a[i].s[k + 1] == a[i].s[j])
                p[i].push_back(++k);
            else
                p[i].push_back(0);
        }
    }
    while(q--)
    {
        int ans = 0;
        string x, y;
        cin >> x >> y;
        x = "+" + x, y = '+' + y;
        int l = x.length() - 1;
        int j = 0;
        for(int k = 1; k <= n; k++)
        {
            int ls = a[k].s.length() - 1;
            j = 0;
            for(int i = 2; i <= l; i++)
            {
                while(j > 0 && a[k].s[j + 1] != x[i]) j = p[k][j];
                if(a[k].s[j + 1] == x[i])
                    j++;
                if(j == ls)
                {
                    // cout << a[k].s << endl;
                    string ne = x;
                    for(int e = i - j + 1; e <= i; e++)
                        ne[e] = a[k].t[e - (i - j + 1) + 1];
                    if(ne == y)
                        ans++;
                    j = p[k][j];
                }
            }
        }
        // printf("%d\n", ans);
        cout << ans << endl;
    }
    return 0;
}