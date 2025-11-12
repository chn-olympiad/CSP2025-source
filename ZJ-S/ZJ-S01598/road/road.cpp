#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7+10, M = 1e4+10;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
int n,m,k,ans;
int c[11][M],vis[N],o[11];
int e[N],h[N],ne[N],nw[N],idx;
priority_queue<PIII,vector<PIII>,greater<PIII>> q;

void add(int u,int v,int w){
    ne[++idx] = h[u];
    h[u] = idx;
    e[idx] = v;
    nw[idx] = w;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
        add(y,x,z);
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i][0];
        for(int j = 1;j <= n;j++) cin >> c[i][j];
    }
    for(int i = h[1];i;i = ne[i]) q.push({nw[i], {e[i], 0}});
    for(int i = 1;i <= k;i++){
        for(int j = 2;j <= n;j++) q.push({c[i][0] + c[i][1] + c[i][j], {j, i}});
    }
    vis[1]++;
    while(q.size()){
        int w = q.top().first, t = q.top().second.first, z = q.top().second.second;
        q.pop();
        if(vis[t]) continue;
        vis[t]++;
        if(z) o[z]++;
        ans += w;
        for(int i = h[t];i;i = ne[i]) if(!vis[e[i]]) q.push({nw[i], {e[i], 0}});
        for(int i = 1;i <= k;i++){
            for(int j = 2;j <= n;j++) if(!vis[j]){
                if(!o[i]) q.push({c[i][0] + c[i][t] + c[i][j], {j, i}});
                else q.push({c[i][t] + c[i][j], {j, i}});
            }
        }
    }
    cout << ans << endl;
    return 0;
}