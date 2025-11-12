#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e6+5;
inline int min(int x, int y) { return x > y ? y : x; }
inline int max(int x, int y) { return x > y ? x : y; }

int n, q;
string s[MAXN][5];
int len[MAXN];
int nwl[MAXN], nwr[MAXN];
string t1, t2;
int len1, len2;
int wl, wr;

inline void solve()
{
    int ans = 0;
    wl = 0x3f3f3f3f, wr = 0xc0c0c0c0;
    cin >> t1 >> t2;
    len1 = t1.length(); len2 = t2.length();
    if(len1 != len2)
    {
        printf("0\n");
        return;
    }
    for(int i = 0; i < len1; i++)
    {
        if(t1[i] != t2[i])
        {
            wl = min(wl, i);
            wr = max(wr, i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(nwr[i] - nwl[i] != wr - wl) continue;
        if(len1 < len[i]) continue;
        if(nwl[i] > wl) continue;
        if(len[i] - nwr[i] - 1 > len1 - wr - 1) continue;
        bool ok = true;
        for(int it1 = 0, it2 = wl - nwl[i]; it1 < len[i]; it1++, it2++)
        {
            if(s[i][1][it1] != t1[it2] || s[i][2][it1] != t2[it2])
            {
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i][1] >> s[i][2];
        len[i] = s[i][1].length();

        nwl[i] = 0x3f3f3f3f, nwr[i] = 0xc0c0c0c0;
        for(int j = 0; j < len[i]; j++)
        {
            if(s[i][1][j] != s[i][2][j])
            {
                nwl[i] = min(nwl[i], j);
                nwr[i] = max(nwr[i], j);
            }
        }
    }
    for(int i = 1; i <= q; i++)
    {
        solve();
    }


    return 0;
}