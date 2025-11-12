#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ent putchar('\n')
#define sp putchar(' ')
#define pii pair<int,int>
#define dbg puts("-----------------qaq----------------")
#define fi first
#define se second
#define pl (p<<1)
#define pr ((p<<1)|1)
const int mod=998244353,inf=LONG_LONG_MAX/4;
int read(){int t;scanf("%lld",&t);return t;}
void write(int x){printf("%lld",x);return;}
const int N=1e4+10,RN=1e4;
const int M=1e6+10,RM=1e6;
const int K=1e1+5,RK=1e1;
int n,m,k,cnt,ans=inf;
struct node{
    int u,v,w;
}a[M],b[N],qaq[N*11];
int c[K],d[N][K];
int fa[N+K];
inline int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline bool cmp(const node& x,const node& y){return x.w<y.w;}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        a[i].u=read(),a[i].v=read(),a[i].w=read();
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            d[j][i]=read();
        }
    }
    sort(a+1,a+m+1,cmp);
    int res=0;
    for(int i=1;i<=m;i++){
        int u=a[i].u,v=a[i].v,w=a[i].w;
        int nu=getf(u),nv=getf(v);
        if(nu!=nv){
            b[++cnt]={u,v,w};
            fa[nv]=nu;
            res+=w;
            if(cnt==n-1) break;
        }
    }
    ans=min(ans,res);
    for(int i=0;i<(1<<k);i++){
        int len=cnt,ns=n;
        res=0;
        for(int j=1;j<=n+k;j++) fa[j]=j;
        for(int j=1;j<=len;j++) qaq[j]={b[j].u,b[j].v,b[j].w};
        for(int j=1;j<=k;j++){
            if((1<<j-1)&i){
                res+=c[j];
                ns++;
                for(int t=1;t<=n;t++){
                    qaq[++len]={j+n,t,d[t][j]};
                }
            }
        }
        sort(qaq+1,qaq+len+1,cmp);
        int tmp=0;
        for(int j=1;j<=len;j++){
            int u=qaq[j].u,v=qaq[j].v,w=qaq[j].w;
            int nu=getf(u),nv=getf(v);
            if(nu!=nv){
                fa[nv]=nu;
                res+=w;
                tmp++;
                if(tmp==ns-1) break;
            }
        }
        ans=min(ans,res);
    }
    write(ans),ent;
    return 0;
}
