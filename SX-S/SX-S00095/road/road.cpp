#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50;
int n,m,k,ans,cnt;
int co[15][N],c[15];
int f[N];
struct node{
    int u,v,w;
    bool friend operator < (const node &A,const node &B){
        return A.w<B.w;
    }
}a[N];
int find(int x){
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    cnt=m;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int p=0;
        for(int j=1;j<=n;j++){
            cin>>co[i][j];
            if(co[i][j]==0)p=j;
        }
        if(p!=0){
            for(int j=1;j<=n;j++)a[++cnt]={p,j,co[i][j]};
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=1;i<=cnt;i++){
        int pu=find(a[i].u),pv=find(a[i].v);
        if(pu!=pv){
            f[pu]=pv;
            ans+=a[i].w;
        }
    }
    cout<<ans;

    return 0;
}