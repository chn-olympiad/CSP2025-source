#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10,M = 2e6+10;
int n,m,k,tot;
struct edge{
    int u,v;
    int w;
    bool operator < (const edge &y) const{
        return w < y.w;
    }
} e[M];
int id[N];
int b[15][N];
int f[N][N];
int find(int x){
    if(id[x] == x)  return x;
    else    return id[x] = find(id[x]);
}
void merge(int x,int y){
    int idx = find(x),idy = find(y);
    id[idx] = idy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    memset(f,0x3f,sizeof f);
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(k != 0){
            if(u > v)   swap(u,v);
            f[u][v] = min(f[u][v],w);
        } else {
            e[++tot] = {u,v,w};
        }
    }
    for(int x = 1;x <= k;x++){
        int c;
        cin >> c;
        for(int j = 1;j <= n;j++){
            cin >> b[x][j];
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                f[i][j] = min(f[i][j],b[x][i]+b[x][j]);
            }
        }
    }
    if(k != 0){
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(f[i][j] != 0x3f3f3f3f)	e[++tot] = {i,j,f[i][j]};
                //cout << i << ' ' << j << ':' << f[i][j] << '\n';
            }
        }
    }
    sort(e+1,e+tot+1);
    for(int i = 1;i <= n;i++)   id[i] = i;
    int ch = 0;
    long long ans = 0;
    for(int i = 1;i <= tot;i++){
        int u = e[i].u,v = e[i].v;
        long long w = e[i].w;
        if(find(u) != find(v)){
            merge(u,v);
            ans += w,ch++;
        }
        if(ch == n-1)   break;
    }
    cout << ans;
    return 0;
}
