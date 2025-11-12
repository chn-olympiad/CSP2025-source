#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k, fa[N], siz[N], wei[N], ans = 0x3f3f3f3f3f3f3f3f;
struct Edge{int x, y, w;}e[M], e1[15][N];
bool cmp(Edge A, Edge B){return A.w < B.w;}
vector<Edge> v;
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x != y) fa[x] = y;
}
int sum, pos[20];
void kruskal(int flag, int res){
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
        if(find(e[i].x) != find(e[i].y)){
            merge(e[i].x, e[i].y), res += e[i].w;
            if(!flag) v.push_back(e[i]);
        }
    ans = min(ans, res);
}
signed main(){
    // freopen("example/road1.in", "r", stdin);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> e[i].x >> e[i].y >> e[i].w;
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= k; i++){
        cin >> wei[i];
        for(int j = 1, x; j <= n; j++) cin >> x, e1[i][j] = {i + n, j, x};
        sort(e1[i] + 1, e1[i] + 1 + n, cmp);
    }
    kruskal(0, 0);
    for(int s = 1; s < (1 << k); s++){
        int sum = 0; m = v.size();
        for(int i = 0; i < (int)v.size(); i++) e[i + 1] = v[i];
        for(int i = 1; i <= k; i++)
            if((s >> (i - 1)) & 1){
                sum += wei[i];
                for(int j = 1; j <= n; j++) m++, e[m] = e1[i][j];
            }
        sort(e + 1, e + 1 + m, cmp);
        kruskal(1, sum);
    }
    cout << ans << endl;
    return 0;
}