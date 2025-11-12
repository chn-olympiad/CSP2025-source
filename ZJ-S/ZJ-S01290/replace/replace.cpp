#include<bits/stdc++.h>
using namespace std;

bool f1;
typedef unsigned long long uLL;
typedef long long LL;
const int N = 2e5 + 10, M = 5e6 + 10, mod = 999999937, base = 13331;
int rt[N], cntr;
int tr1[M][26], tr2[M][26], idx, idx2 = 1;
vector<int> que[M];
vector<int> son[M];
vector<int> pts[M];
unordered_map<uLL, unordered_map<int, int>> mp;
string ss[N], st[N];
char s1[M], s2[M];
int ans[N];
int cnt[M];
int n, q;
bool f2;

uLL gethash1(int l, int r)
{
    uLL ret = 0;
    for(int i = l; i <= r; i ++) ret = ret * base + s1[i];
    for(int i = l; i <= r; i ++) ret = ret * base + s2[i];
    return ret;
}

int gethash2(int l, int r)
{
    int ret = 0;
    for(int i = l; i <= r; i ++) ret = ((LL)ret * base % mod + s1[i]) % mod;
    for(int i = l; i <= r; i ++) ret = ((LL)ret * base % mod + s2[i]) % mod;
    return ret;
}

void insert1(int r, int pos, int id)
{
    int p = rt[r];
    // cerr << p << " " << pos << endl;
    for(int i = pos; i >= 1; i --)
    {
        int u = s1[i] - 'a';
        if(!tr1[p][u]) tr1[p][u] = ++ idx, son[p].push_back(u);
        p = tr1[p][u];
    }
    pts[p].push_back(id);
    // cerr << p << " " << id << endl;
}

void init1(int id, int pos, int ed)
{
    string g = "";
    for(int i = pos; i <= ed; i ++) g += s2[i];
    ss[id] = g;
}

void init2(int id, int pos, int ed)
{
    string g = "";
    for(int i = pos; i <= ed; i ++) g += s2[i];
    st[id] = g;
}

void maketag(int r, int pos, int id)
{
    int p = rt[r];
    for(int i = pos; i >= 1; i --)
    {
        int u = s1[i] - 'a';
        if(!tr1[p][u])
        {
            // cerr << p << endl;
            que[p].push_back(id);
            return;
        }
        p = tr1[p][u];
    }
    // cerr << p << endl;
    que[p].push_back(id);
}

void insert2(int x)
{
    // cerr << x << endl;
    int p = 1;
    for(int i = 0; ss[x][i]; i ++)
    {
        int u = ss[x][i] - 'a';
        if(!tr2[p][u]) tr2[p][u] = ++ idx2;
        p = tr2[p][u];
    }
    cnt[p] ++;
}

void del2(int x)
{
    int p = 1;
    for(int i = 0; ss[x][i]; i ++)
    {
        int u = ss[x][i] - 'a';
        p = tr2[p][u];
    }
    cnt[p] --;
}

int query(int x)
{
    int p = 1;
    int ret = cnt[p];
    for(int i = 0; st[x][i]; i ++)
    {
        int u = st[x][i] - 'a';
        if(!tr2[p][u]) break;
        p = tr2[p][u];
        ret += cnt[p];
    }
    // cerr << ret << endl;
    return ret;
}

void dfs(int u)
{ 
    // cerr << "-- " << u << endl;
    for(auto x : pts[u]) insert2(x);
    for(auto x : que[u]) ans[x] = query(x);
    for(auto x : son[u]) dfs(tr1[u][x]);
    for(auto x : pts[u]) del2(x);
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // freopen("replace.err", "w", stderr);
    cin >> n >> q;
    // int ccnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; s1[j]; j ++) s1[j] = 0;
        for(int j = 1; s2[j]; j ++) s2[j] = 0;
        scanf("%s%s", s1 + 1, s2 + 1);
        int len = strlen(s1 + 1);
        // ccnt += len + len;
        int p1 = 1, p2 = len;
        while(p1 <= len && s1[p1] == s2[p1]) p1 ++;
        if(p1 > len)
        {
            i --, n --;
            continue;
        }
        while(p2 >= 1 && s1[p2] == s2[p2]) p2 --;
        uLL hashv1 = gethash1(p1, p2);
        int hashv2 = gethash2(p1, p2);
        // cerr << hashv1 << " " << hashv2 << endl;
        int p;
        if(!mp[hashv1].count(hashv2)) cntr ++, p = cntr, rt[cntr] = ++ idx, mp[hashv1][hashv2] = cntr;
        else p = mp[hashv1][hashv2];
        insert1(p, p1 - 1, i);
        init1(i, p2 + 1, len);
        // cerr << p1 << " " << p2 << " " << ss[i] << endl;
    }
    for(int i = 1; i <= q; i ++)
    {
        for(int j = 1; s1[j]; j ++) s1[j] = 0;
        for(int j = 1; s2[j]; j ++) s2[j] = 0;
        scanf("%s%s", s1 + 1, s2 + 1);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        // ccnt += len1 + len2;
        if(len1 != len2)
        {
            ans[i] = 0;
            continue;
        }
        int p1 = 1, p2 = len1;
        while(p1 <= len1 && s1[p1] == s2[p1]) p1 ++;
        while(p2 >= 1 && s1[p2] == s2[p2]) p2 --;
        // cerr << p1 << " " << p2 << endl;
        uLL hashv1 = gethash1(p1, p2);
        int hashv2 = gethash2(p1, p2);
        // cerr << hashv1 << " " << hashv2 << endl;
        if(!mp[hashv1].count(hashv2))
        {
            ans[i] = 0;
            continue;
        }
        int p = mp[hashv1][hashv2];
        // cerr << p << endl;
        maketag(p, p1 - 1, i);
        init2(i, p2 + 1, len1);
    }
    for(int i = 1; i <= cntr; i ++) dfs(rt[i]);
    for(int i = 1; i <= q; i ++) printf("%d\n", ans[i]);
    // cerr << ccnt << endl;
    return 0;
}