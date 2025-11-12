#include<bits/stdc++.h>
using namespace std;
// #define int long long 
int n,m,k;
int fa[200200];
int a[2002002],b[2002002],c[2002002];
int aa[1025][10110],bb[1025][10110],cc[1025][10110];
int p[200200];
int id[2002002],tot;
int at[200200],bt[200200],ct[200200],sz[200200];
pair<int,int> pp[12][10110];
bool cmp(int x,int y){
    return c[x]<c[y];
}
int find(int x){
    return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
void bing(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return ;
    if(sz[x]>sz[y])swap(x,y);
    fa[x]=y;sz[y]+=sz[x];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    cin>>a[i]>>b[i]>>c[i],id[i]=i;
    sort(id+1,id+m+1,cmp);
    for (int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    for (int i=1;i<=m;i++){
        int x=id[i];
        if(find(a[x])!=find(b[x])){
            bing(a[x],b[x]);tot++;
            aa[0][tot]=a[x],bb[0][tot]=b[x],cc[0][tot]=c[x];
        }
    }
    // cout<<tot<<"!!\n";
    // cerr<<"$$$\n";
    for (int i=1;i<=k;i++){
        cin>>p[i];
        for (int j=1;j<=n;j++)
        cin>>pp[i][j].first,pp[i][j].second=j;
        sort(pp[i]+1,pp[i]+n+1);
    }
    int kk=1<<k;
    long long ans=1e18;
    for (int i=0;i<kk;i++){
        long long sum=0;
        for (int j=1;j<=k;j++)
        if(i>>(j-1)&1){
            sum+=p[j];
        }
        if(i!=0){
            int t=i&(-i);
            int tt=__lg(t)+1;
            int w=1,ww=0;
            for (int j=1;j<=n;j++){
                while(aa[i^t][w]!=0&&cc[i^t][w]<=pp[tt][j].first)at[++ww]=aa[i^t][w],bt[ww]=bb[i^t][w],ct[ww]=cc[i^t][w],w++;
                ww++;at[ww]=pp[tt][j].second,bt[ww]=tt+n,ct[ww]=pp[tt][j].first;
            }
            while(aa[i^t][w]!=0)at[++ww]=aa[i^t][w],bt[ww]=bb[i^t][w],ct[ww]=cc[i^t][w],w++;
            w=0;
            for (int j=1;j<=n+k;j++)fa[j]=j,sz[j]=1;
            // cerr<<i<<"!!"<<ww<<"\n";
            for (int j=1;j<=ww;j++){
                int x=at[j],y=bt[j],z=ct[j];
                if(find(x)!=find(y)){
                    bing(x,y);
                    aa[i][++w]=x,bb[i][w]=y,cc[i][w]=z;
                }
            }
        }
        for (int j=1;aa[i][j]!=0;j++)
        sum+=cc[i][j];
        // cout<<i<<"~~"<<sum<<"\n";
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
}