#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 15;
const int M = 15;
const ll inf = 1e18 + 7;
int n,m,k;
vector<array<int,3>> edge;
int far[N],rk[N];
int c[M];
bool vis[M];
int find(int x){
    return x == far[x] ? x : far[x] = find(far[x]);
}
void merge(int u,int v){
    int fu = find(u),fv = find(v);
    if(rk[fu] < rk[fv]) swap(fu,fv);
    far[fv] = fu;rk[fu] += rk[fv];
}
ll kruscal(int s){
    int des = n;
    ll ans = 0;
    for(int i = 1;i <= n + k;i ++)
        far[i] = i,rk[i] = 1;
    for(int i = 0;i < k;i ++){
        vis[i] = (s >> i & 1);
        if(vis[i]) des ++,ans += c[i];
    }int cnt = 0;
    for(auto x : edge){
        int u = x[0],v = x[1],w = x[2];
        if(u > n && !vis[u - n - 1]) continue;
        if(v > n && !vis[v - n - 1]) continue;
        if(find(u) == find(v)) continue;
        ans += w;cnt ++;
        merge(u,v);
        if(cnt == des - 1) break;
    }return ans;
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i ++){
        int u,v,w;cin >> u >> v >> w;
        edge.push_back({u,v,w});
    }
    for(int i = 0;i < k;i ++){
        cin >> c[i];
        for(int j = 1;j <= n;j ++){
            int w;cin >> w;
            edge.push_back({n + i + 1,j,w});
        }
    }
    sort(edge.begin(),edge.end(),[&](const array<int,3> a,const array<int,3> b){
        return a[2] < b[2];
    });
    ll minn = inf;
    for(int s = 0;s < (1 << k);s ++){
        ll res = kruscal(s);
        minn = min(res,minn);
    }cout << minn << '\n';
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while(T --) solve();
    return 0;
}
/*
at first,I think it it Brouvka(?)
*/