#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define int long long
#define pii pair<int,int>
int head[N],cnt=0;
struct node{
    int x,y,w;
}e[N];
int n,m,k,f[N];
int c[15][N],ans=0;
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool cmp(node xx,node yy){
    return xx.w<yy.w;
}
bool flag=0;
int vis[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0) flag=1;
        }
    }
    for(int i=1;i<=m;i++){
        int xx=e[i].x,yy=e[i].y;
        int fx=find(xx),fy=find(yy);
        if(fx==fy) continue;
        ans+=e[i].w; f[yy]=find(f[xx]);
    }
    cout<<ans<<'\n';
    return 0;
}
