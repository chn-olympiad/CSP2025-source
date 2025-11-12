//  一道都不会 

#include <bits/stdc++.h>
#define fr {freopen("road.in","r",stdin);freopen("road.out","w",stdout);}
#define qr {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define int long long
#define N 10100
#define M 1000005
using namespace std;

int n,m,k;

int f[N];

int find(int x){
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}

void ad(int x,int y){
    x = find(x);
    y = find(y);
    if(x < y) swap(x,y);
    f[x] = y;
    return ;
}

bool check(int x,int y){
    x = find(x);
    y = find(y);
    return (x == y);
}

struct Edge{
    int u,v,w;
    bool operator < (const Edge b) const{
        return w < b.w;
    }
} e[M];

signed main(){
    fr;
    qr;
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;i++) f[i] = i;
    for(int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
    int cnt = 0;
    int ans = 0;
    sort(e+1,e+1+m);
    for(int i = 1;i <= m;i++){
        if(!check(e[i].u,e[i].v)){
            ans += e[i].w;
            ad(e[i].u,e[i].v);
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout << ans << '\n';
    return 0;
}
