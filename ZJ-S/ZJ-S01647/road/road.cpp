#include <bits/stdc++.h>
using namespace std;

#define N 10050
#define M 1000010
#define K 20

struct node{ int s, e, val; };

int n, m, k;
node a[M], g[N];
int c[K], f[N], len;
node mp[K][N];
long long res;

void merge(node ans[], node a[], int la, node b[], int lb){
    int noa = 1, nob = 1, tmp = 0;
    while(noa <= la && nob <= lb){
        if(a[noa].val < b[nob].val) ans[++tmp] = a[noa++];
        else ans[++tmp] = b[nob++];
    }
    while(noa <= la) ans[++tmp] = a[noa++];
    while(nob <= lb) ans[++tmp] = b[nob++];
}

int fnd(int x){ return f[x] == x ? x : f[x] = fnd(f[x]); }

void dfs(int u, long long val){
    if(u == k + 1) return;
    dfs(u + 1, val);
    node b[N]{}, s[N * 2]{};
    for(int i = 1;i <= len;i++) b[i] = g[i];
    merge(s, g, len, mp[u], n);club5
    for(int i = 1;i <= n + k;i++) f[i] = i;
    int num = 0; long long ans = 0;
    for(int i = 1;i <= len + n;i++){
        int fa = fnd(s[i].s), fb = fnd(s[i].e);
        if(fa == fb) continue;
        num++, f[fb] = fa, ans += s[i].val;
        g[num] = s[i];
    }
    len++;
    res = min(res, ans + val + c[u]);
    dfs(u + 1, val + c[u]);
    len--;
    for(int i = 1;i <= len;i++) g[i] = b[i];
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k; int tmp;
    for(int i = 1;i <= m;i++) cin >> a[i].s >> a[i].e >> a[i].val;
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++)
            cin >> tmp, mp[i][j] = {n + i, j, tmp};
        sort(mp[i] + 1, mp[i] + n + 1, [&](node x, node y){return x.val < y.val;});
    }
    sort(a + 1, a + m + 1, [&](node x, node y){return x.val < y.val;});
    for(int i = 1;i <= n;i++) f[i] = i; int num = 0;
    for(int i = 1;i <= m;i++){
        int fa = fnd(a[i].s), fb = fnd(a[i].e);
        if(fa == fb) continue;
        num++, f[fb] = fa, res += a[i].val;
        g[num] = a[i];
        if(num == n - 1) break;
    }
    len = n - 1; dfs(1, 0);
    cout << res << endl;
    return 0;
}