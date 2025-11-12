/* 进行最小生成树 对于每个可修复边检查是否有乡镇可以松弛这条边 选出最小值*/
/* 对于每次松弛检查 要注意判断此城乡是否已经城市化 避免重复计算ci*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u,v,w,c[15],a[15][10005],vis[15],vis2[15][10005];//vis表示城乡是否城市化
vector<int> can[1000005];//能够松弛i边的乡镇
int Cost[15],ans;
struct Road {
    int u,v,w,id;
    bool operator<(const Road k) const{
        return w < k.w;
    }
};
priority_queue<Road> q;
signed main() {
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        cin >> u >> v >> w;
        q.push((Road){u,v,w,i});//存储可修复边
    }
    for (int i = 1;i <= k;i++) {
        cin >> c[i];
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    while (!q.empty()) {
        u = q.top().u;
        v = q.top().v;
        w = q.top().w;
        int id = q.top().id;
        q.pop();
        int minx = w;
        int pos = -1;
        int cost[15];
        memset(cost,0,sizeof(cost));
        for (int i = 1;i <= k;i++) {
            if (!vis[i]) {
                cost[i] += c[i];
                Cost[i] += c[i];
            }
            if (!vis2[i][u]) {
                cost[i] += a[i][u];
                Cost[i] += a[i][u];
            }
            if (!vis2[i][v]) {
                cost[i] += a[i][v];
                Cost[i] += a[i][v];
            }
            if (cost[i] <= minx) {
                minx = cost[i];
                pos = i;
            }
        }
        if (pos != -1) {
            for (int i = 1;i <= k;i++) {
                if (cost[i] == minx) {
                    can[id].push_back(i);
                    vis[i] = 1;
                    vis2[i][u] = 1;
                    vis2[i][v] = 1;
                }
            }
        }
        ans += minx;
    }
    for (int i = 1;i <= m;i++) {
        if (can[i].end() - can[i].begin() > 1) {
            int cnt = 0,maxn = -1,pos = -1;
            for (auto p : can[i]){
                if (!vis[p]) {
                    continue;
                }
                cnt += Cost[p];
                if (Cost[p] < maxn) {
                    vis[p] = 0;
                }
                if (Cost[p] == maxn && pos != -1) {
                    vis[p] = 0;
                }
                if (Cost[p] > maxn) {
                    maxn = Cost[p];
                }
            }
            ans -= (cnt - maxn);
        }
    }
    cout << ans;
    return 0;
}
//written by Lxsh1203
