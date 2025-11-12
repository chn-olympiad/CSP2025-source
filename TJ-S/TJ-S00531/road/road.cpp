#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;

struct Edge{
    int u,v,w;
}bian[1000006];
struct Node {
    int v,w;
};
vector<Node > e[100005];

int vis[100005],dis[100005];
int c[100],cntry[10][100005];

int krusk(int s){
    int ans = 0;
    for (int i = 0;i<=n;i++){
        dis[i] = 1e18;
    }
    dis[s] = 0;
    for (int i = 1;i<=n;i++){
        int u = 0;
        for (int j = 1;j<=n;j++){
            if (vis[j] == 0 && dis[j]<dis[u]){
                u = j;
            }
        }
        vis[u] = 1;
        ans += dis[u];
        for (Node t:e[u]){
            if (vis[t.v] == 0)dis[t.v] = min(dis[t.v],t.w);
        }
        /*
        cout<<u<<" "<<dis[u]<<endl<<"-----";
        for (int j = 1;j<=n;j++)cout<<dis[j]<<" ";
        cout<<endl<<"-----";
        for (int j = 1;j<=n;j++)cout<<vis[j]<<" ";
        cout<<endl;
        */
    }
    return ans;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for (int i = 1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        bian[i] = {x,y,z};

        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }

    if (k == 0){
        cout<<krusk(1);

        return 0;
    }

    int cnt0 = 0;
    for (int i = 1;i<=k;i++){
        cin>>c[i];
        for (int j = 1;j<=n;j++){
            cin>>cntry[i][j];
        }

        if (c[i] == 0)cnt0++;
    }

   // if (cnt0 == k){
            //cout<<"ttt";
        for (int i = 1;i<=n;i++){
            for (int j = i;j<=n;j++){
                if (i == j)continue;
                int minn = 1e18;
                for (int p = 1;p<=k;p++){
                    minn = min(minn,cntry[p][i] + cntry[p][j]);
                }
                e[i].push_back({j,minn});
                e[j].push_back({i,minn});
            }
        }

        cout<<krusk(1);
        return 0;
   // }
  //  return 0;
}
/*
5 8 0
1 2 7
2 3 3
3 4 8
1 3 5
1 4 2
1 5 6
3 5 9
2 5 5
*/
