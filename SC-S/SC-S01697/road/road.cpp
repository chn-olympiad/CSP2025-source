#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e4+14,M=2e6+26;
int dad[N];
int Find(int x){
    if(dad[x]!=x)
        dad[x]=Find(dad[x]);
    return dad[x];
}
void Union(int x,int y){
    int fx=Find(x),fy=Find(y);
    dad[fy]=fx;
    return;
}
struct edge{
    int u,v,w;
}e[M],e_[M];
int n,m,k;
int c[11],a[11][N];
long long ans=1e18;
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]=edge{u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(int t=0;t<(1<<k);t++){//2^k
        for(int i=1;i<=m;i++)
            e_[i]=e[i];
        long long sum=0;
        int cnt=0,pos=m;
        for(int i=1;i<=k;i++)
            if((t>>(i-1))&1){
                cnt++;
                sum+=c[i];
                for(int j=1;j<=n;j++)
                    e_[++pos]=edge{n+cnt,j,a[i][j]};
            }
        if(sum>=ans)
            continue;
        sort(e_+1,e_+1+pos,[&](const edge&X,const edge&Y)->bool{
            return X.w<Y.w;
        });
        for(int i=1;i<=cnt+n;i++)
            dad[i]=i;
        int cnte=0;
        for(int i=1;i<=pos;i++){
            if(sum>=ans)
                break;
            if(cnte==n+cnt-1)
                break;
            edge E=e_[i];
            if(Find(E.u)!=Find(E.v)){
                sum+=E.w;
                cnte++;
                Union(E.u,E.v);
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}