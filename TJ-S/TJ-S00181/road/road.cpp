#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e4+15;
const int M=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k;
ll fd[N][N],a[11],aa[11],ans,dis[M],vis[N],cnt;

void update(int x){
    for(int i=1;i<=n+k;i++){
        if(fd[x][i]&&!vis[i]){
            dis[i]=min(fd[x][i],dis[i]);
        }
    }
}

void solve(){
    int x=1;
    cnt++;vis[x]=1;fd[x][x]=INF;
    update(x);
    while(cnt<n){
        ll minn=1e9;int used=-1;
        for(int i=1;i<=n+k;i++){
            if(minn>dis[i]&&!vis[i]){
                minn=dis[i];
                used=i;
            }
        }
        vis[used]=1;
        ans+=dis[used];
        cnt++;
        fd[x][used]=INF;
        if(used>n){
            /*
            if(aa[used]){
                ans-=a[used];
            }
            aa[used]=1;
            */
            for(int j=1;j<=n;j++){
                fd[used][j]-=a[used-n];
                fd[j][used]-=a[used-n];
            }
            cnt--;
        }
        update(used);
        x=used;
    }
}

void solve2(){
    int x=1;
    cnt++;vis[x]=1;fd[x][x]=INF;
    update(x);
    while(cnt<n){
        ll minn=1e9;int used=-1;
        for(int i=1;i<=n+k;i++){
            if(minn>dis[i]&&!vis[i]){
                minn=dis[i];
                used=i;
            }
        }
        vis[used]=1;
        ans+=dis[used];
        cnt++;
        fd[x][used]=INF;
        update(used);
        x=used;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k+1;i++){
        dis[i]=INF;
    }
    for(int i=1;i<=n+k+1;i++){
        for(int j=1;j<=n+k+1;j++){
            fd[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        fd[u][v]=w;
        fd[v][u]=w;
    }
    for(int j=n+1;j<=n+k;j++){
        cin>>a[j-n];
        for(int i=1;i<=n;i++){
            int w;
            cin>>w;
            fd[j][i]=w+a[j-n];
            fd[i][j]=w+a[j-n];
        }
    }
    if(k==0){
        solve2();
        cout<<ans;
        return 0;
    }
    solve();
    cout<<ans;
    return 0;
}
