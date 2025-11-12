#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k;
struct sdf{
    int u, v;
    long long w;
}rd[N];
bool cmp(sdf x, sdf y){
    return x.w < y.w;
}
int vis[N];
int ans;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++ i){
        cin >> rd[i].u >> rd[i].v >> rd[i].w;
    }
    sort(rd + 1, rd + m + 1, cmp);
    int cnt = 0, x = 1;
    while(cnt <= n - 1){
        if(vis[rd[x].u] && vis[rd[x].v]){
            x ++;
            continue;
        }
        vis[rd[x].u] = 1, vis[rd[x].v] = 1;
        cnt ++;
        ans += rd[x].w;
    }
    cout << ans;
    return 0;
}