#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5,M=1e6+1e5+5;
int n,m,K;
struct edge{
    int u,v,w;
}E[M];
int c[12],a[12][N],at[N];
int f[N];
int fd(int x){
    if(f[x]==x)return x;
    return f[x]=fd(f[x]);
}
int Aflag;
void subA(){
    for(int i=1;i<=K;++i){
        for(int j=1;j<=n;++j){
            E[++m]={at[i],j,a[i][j]};
        }
    }
    sort(E+1,E+m+1,[&](edge x,edge y){
        return x.w<y.w;
    });
    int ans=0,cnt=0;
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=1;i<=m;++i){
        int x=fd(E[i].u),y=fd(E[i].v),w=E[i].w;
        if(x==y)continue;
        ans+=w,cnt++;
        f[x]=y;
        if(cnt==n-1)break;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>K;
    Aflag=1;
    for(int i=1;i<=m;++i){
        cin>>E[i].u>>E[i].v>>E[i].w;
    }
    for(int i=1;i<=K;++i){
        cin>>c[i];
        if(c[i])Aflag=0;
        int tmp=0;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if(!a[i][j])tmp=1,at[i]=j;
        }
        if(!tmp)Aflag=0;
    }
    if(Aflag){
        subA();
        return 0;
    }
    int om=m,on=n,Ans=1e18;
    for(int S=0;S<(1<<K);++S){
        int ans=0;
        for(int i=1;i<=K;++i){
            if(S&(1<<(i-1))){
                ans+=c[i];
                n++;
                for(int j=1;j<=on;++j){
                    E[++m]={n,j,a[i][j]};
                }
            }
        }
        for(int i=1;i<=n;++i)f[i]=i;
        int cnt=0;
        sort(E+1,E+m+1,[&](edge x,edge y){
            return x.w<y.w;
        });
        for(int i=1;i<=m;++i){
            int x=fd(E[i].u),y=fd(E[i].v),w=E[i].w;
            if(x==y)continue;
            ans+=w,cnt++;
            f[x]=y;
            if(cnt==n-1)break;
        }
        Ans=min(Ans,ans);
        m=om,n=on;
    }
    cout<<Ans<<"\n";
}