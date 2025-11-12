#include <bits/stdc++.h>
using namespace std;

const int N = 200005, Len = 5000005 , mod = 998244353;
int n, q, L[N], R[N], ans[N] , pre[2][Len], po[Len], h[2][N];
string s[N][2], t[N][2];
map<pair<int , int>, vector<int>> mp;

inline int ha(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = (res * 26 % mod + (s[i] - 'a')) % mod;
    return res;
}

inline bool check(string s1 , int tp , int siz , int has , int pos)
{
    if (s1.size() < siz + pos) return 0;
    return (pre[tp][pos + siz - 1] - (pos == 0 ? 0 : pre[tp][pos - 1]) * po[siz] % mod + mod) % mod == has;
}

signed main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    po[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
        for (int j = 0 ; j < s[i][0].size() ; j++)
            if(s[i][0][j] != s[i][1][j]) {L[i] = j; break;}
        for (int j = s[i][0].size() - 1; j; j--)
            if(s[i][0][j] != s[i][1][j]) {R[i] = j; break;}
        string tmp0 = "" , tmp1 = "";
        for(int j = L[i] ; j <= R[i] ; j++) tmp0 += s[i][0][j] , tmp1 += s[i][1][j];
        mp[{ha(tmp0), ha(tmp1)}].push_back(i);
        h[0][i] = ha(s[i][0]); h[1][i] = ha(s[i][1]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t[i][0] >> t[i][1];
        if(t[i][0].size() != t[i][1].size()) {printf("0\n"); continue;}
        int l, r;
        pre[0][0] = t[i][0][0] - 'a';
        pre[1][0] = t[i][1][0] - 'a';
        for(int j = 1 ; j < t[i][0].size() ; j++)
        {
            pre[0][j] = (pre[0][j - 1] * 26 % mod + (t[i][0][j] - 'a')) % mod;
            pre[1][j] = (pre[1][j - 1] * 26 % mod + (t[i][1][j] - 'a')) % mod;
            if(!po[j]) po[j] = po[j - 1] * 26 % mod;
        }
        for (int j = 0 ; j < t[i][0].size() ; j++)
            if(t[i][0][j] != t[i][1][j]) {l = j; break;}
        for (int j = t[i][0].size() - 1; j; j--)
            if(t[i][0][j] != t[i][1][j]) {r = j; break;}
        string tmp0 = "" , tmp1 = "";
        for(int j = l ; j <= r ; j++) tmp0 += t[i][0][j] , tmp1 += t[i][1][j];
        if(!mp.count({ha(tmp0), ha(tmp1)})) {printf("0\n"); continue;}
        for(int id : mp[{ha(tmp0), ha(tmp1)}])
        {
            if(check(t[i][0] , 0 , s[id][0].size() , h[0][id] , l - L[id]) && check(t[i][1] , 1 , s[id][1].size() , h[1][id] , l - L[id]))
                ans[i]++;
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}