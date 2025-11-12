#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define pb push_back
#define int long long
const int num=11000;
int n,ans,m,k,c[11],a[11][num],f[num],maxn;
struct node{
    int x,y,w;
}e[num*100],r[num];
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void init(){
    F(i,1,n+10)f[i]=i;
}
bool mg(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return 0;
    f[x]=y;
    return 1;
}
void solve(int sta){
    int sum=0,tot=n,cnt=n-1,tmp=0;
    F(i,1,cnt)e[i]=r[i];
    F(i,0,k-1)if(sta&(1<<i)){
        tot++;sum+=c[i];
        F(j,1,n)if(a[i][j]<maxn){
            e[++cnt]={n+i+1,j,a[i][j]};
        }
    }
    if(sum>=ans)return;
    sort(e+1,e+cnt+1,cmp);
    init();
    
    F(i,1,cnt){
        if(mg(e[i].x,e[i].y)){
            sum+=e[i].w;
            tmp++;
        }
        if(sum>=ans)return;
        if(tmp==tot-1)break;
    }
    ans=min(ans,sum);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    F(i,1,m)cin>>e[i].x>>e[i].y>>e[i].w;
    F(i,0,k-1){
        cin>>c[i];
        F(j,1,n)cin>>a[i][j];
    }
    sort(e+1,e+m+1,cmp);
    int tot=0;
    F(i,1,m){
        if(mg(e[i].x,e[i].y)){
            ans+=e[i].w;
            r[++tot]=e[i];
            maxn=e[i].w;
        }
        if(tot==n-1)break;
    }
    for(int i=1;i<(1<<k);i++){
        solve(i);
    }
    cout<<ans<<endl;
}