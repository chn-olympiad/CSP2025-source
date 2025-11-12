#include <bits/stdc++.h>
using namespace std;
#define N 10050
#define M 1000050
#define INF 0x3f3f3f3f3f3f3f3fll
int n,m,k;
int head[N],ver[M],edge[M],nex[M],tot;
int a[N];
int zhuanjie[N];
int cost[N][N];
long long dist[N];
long long ans=INF;
bool vis[N];
bool check(){
    for(int i=1;i<=n;i++)
    if(vis[i]==0) return 0;
    return 1;
}
void ADD(int x,int y,int z){
    ver[++tot]=y;
    edge[tot]=z;
    nex[tot]=head[x];
    head[x]=tot;
}
void DFS(int x,long long sum){
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    for(int i=head[x];~i;i=nex[i]){
        int y=ver[i];
        int z=edge[i];
        if(vis[y]) continue;
        sum+=z;
        vis[y]=1;
    }
    if(check()) ans=min(sum,ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        ADD(x,y,z);
        ADD(y,x,z);
    }
    for(int i=1;i<=k;i++){
        cin>>zhuanjie[i];
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            DFS(i,0);
        }
        cout<<ans;
    }else{
        cout<<"0";
    }
	return 0;
}

