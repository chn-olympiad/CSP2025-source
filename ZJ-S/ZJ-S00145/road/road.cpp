#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int maxm=1000005;
const int maxS=(1<<10)+5;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while( isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch&15);ch=getchar();}
    return ret*f;
}
int n,m,k,S;
long long ans=LONG_LONG_MAX;
struct edge{
    int u,v,w;
    bool operator<(const edge &B)const{return w<B.w;}
}res[maxS][maxn],tmp[maxm],es[11][maxn];
int fa[maxn*2],c[11],a[11][maxn];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read();k=read();
    S=(1<<k)-1;
    for(int i=1;i<=m;++i){
        tmp[i].u=read();
        tmp[i].v=read();
        tmp[i].w=read();
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int t=1;t<=n;++t){
            es[i][t]=(edge){n+i,t,read()};
        }
        sort(es[i]+1,es[i]+n+1);
    }
    sort(tmp+1,tmp+m+1);
    for(int s=0;s<=S;++s){
        long long ret=0;int cnt=n-1,ls=0;
        for(int i=1;i<=n+k;++i) fa[i]=i;
        for(int i=1;i<=k;++i){
            if(s&(1<<(i-1))){
                ret+=c[i];
                cnt++;
                ls=i;
            }
        }
        if(ls){
            for(int i=1;i<=cnt-1;++i) tmp[i]=res[s^(1<<(ls-1))][i];
            for(int i=1;i<=n;++i) tmp[cnt-1+i]=es[ls][i];
            inplace_merge(tmp+1,tmp+cnt,tmp+cnt+n);
        }
        int cur=0;
        for(int i=1;cur<cnt;++i){
            int u=tmp[i].u,v=tmp[i].v,fu=getfa(u),fv=getfa(v);
            if(fu!=fv){
                fa[fv]=fu;
                ret+=tmp[i].w;
                res[s][++cur]=tmp[i];
            }
        }
        ans=min(ans,ret);
    }
    printf("%lld\n",ans);
    return 0;
}