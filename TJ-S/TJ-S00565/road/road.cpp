#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, ke, x, y, z, o[15][10005], cst[15], fa[10500], E, nl, nr, EE, E3;
struct qq {
    int f, t, w;
} a[100005], b[100005], c[1000005], b2[100005];

#ifdef __linux__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int f(int x) {
    return fa[x] == x ? x : fa[x] = f(fa[x]);
}
/*
inline int readd() {
    int re = 0;
    char u = gc();
    while(!isdigit(u))u = gc();
    while(isdigit(u))re = re * 10 + u - '0', u = gc();
    return re;
}
*/
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> ke;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x,&y,&z);
        //x = readd();
        //y = readd();
        //z = readd();
        c[i] = {x, y, z};
    }
    sort(c + 1, c + m + 1, [](qq x, qq y) {return x.w < y.w;});
    for(int j = 1; j <= n + ke; j++)fa[j] = j;
    for(int i = 1;i<=m;i++){
        int l = f(c[i].f), r = f(c[i].t);
        if(l != r) {
            a[++EE] = c[i];
            fa[l] = r;
        }
    }
    for(int i = 0; i < ke; i++) {
        scanf("%d", &cst[i]);
        for(int j = 1; j <= n; j++){
            scanf("%d", &o[i][j]);
            b2[++E3] = {j, i + n + 1, o[i][j]};
        }
    }
    sort(b2 + 1, b2 + E3 + 1, [](qq x, qq y) {return x.w < y.w;});
    ll ans = 1e18;
    for(int i = 0; i < (1 << ke); i++) {
        ll tot = 0;
        E = 0;
        nl = 1, nr = 1;
        for(int j = 0; j < ke; j++) {
            if(i & (1 << j)) {
                tot += cst[j];
            }
        }
        for(int j = 1;j<=E3;j++){
            if(i&(1<<(b2[j].t -n-1))){
                b[++E] = b2[j];
            }
        }
        //sort(b + 1, b + E + 1, [](qq x, qq y) {return x.w < y.w;});
        for(int j = 1; j <= n + ke; j++)fa[j] = j;
        int lft = n - 1;
        for(int j = 1; j <= EE + E; j++) {
            if(tot>=ans)break;
            if(lft == 0) break;
            qq u;
            if(nl > EE)u = b[nr++];
            else if(nr > E) u = a[nl++];
            else {
                if(a[nl].w < b[nr].w) u = a[nl++];
                else u = b[nr++];
            }
            int l = f(u.f), r = f(u.t);
            if(l != r) {
                tot += u.w;
                fa[l] = r;
                if(l <= n && r <= n)lft--;
            }
        }
        //cout<<tot <<" ";
        ans = min(ans, tot);
    }
    cout << ans;
    return 0;
}
/*
1 2 1
2 3 1
3 4 1
*/

