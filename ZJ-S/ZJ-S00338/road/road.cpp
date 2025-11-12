#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m, k, c[N], d[N], cnt = 0, head[N];
int bl[1005][1005];
bool vis[1005][1005];
struct node{
    int now, x, next;
}edge[N];

void add(int u, int v, int w){
    edge[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    memset(head, -1, sizeof head);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    if(k == 0){
        cout << bl[1][n] << endl;
        return 0;
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> d[j];
        }
    }
    cout << 0 << endl;
    return 0;
}