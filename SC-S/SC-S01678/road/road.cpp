#include<cstdio>
#include<cctype>
#include<algorithm>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf;
template<typename type>
inline void read(type &x)
{
    x=0;
    bool flag=0;char ch=gc();
    while(!isdigit(ch)) flag=ch=='-',ch=gc();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=gc();
    flag?x=-x:0;
}
int n,m,k,a[15][10500],c[15],fa[10500],U,siz[10050];
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
typedef long long ll;
const int MAXM=1e6+10;
ll sum,ans;
bool bd[15];
struct Edge
{
    int u,v;
    ll w;
    inline bool operator<(const Edge &x)const{return w<x.w;}
}e[MAXM*5];
inline void kruskal(int ct)
{
    sum=0;
    for(int i=1;i<=n+k;++i) fa[i]=i,siz[i]=1;
    for(int i=1,cnt=0,u,fu,fv;i<=m;++i)
    {
        if(cnt==n+ct-1) break;
        u=e[i].u,fu=find(u),fv=find(e[i].v);
        if(fu==fv||(u>n&&(!bd[u-n]))) continue;
        sum+=e[i].w,cnt++;
        if(siz[fu]>siz[fv]) swap(fu,fv);
        fa[fu]=fv,siz[fv]+=siz[fu];
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=m;++i) read(e[i].u),read(e[i].v),read(e[i].w);
    ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=k;++i)
    {
        read(c[i]);
        for(int j=1;j<=n;++j)
        {
            read(a[i][j]);
            e[++m]={i+n,j,a[i][j]};
        }
    }
    sort(e+1,e+m+1);
    U=(1<<k)-1;
    for(int s=0;s<=U;++s)
    {
        ll res=0;
        int cnt=0;
        for(int i=1;i<=k;++i)
        {
            bd[i]=0;
            if(s&(1<<(i-1))) res+=c[i],bd[i]=1,cnt++;
        }
        kruskal(cnt);
        if(sum+res<ans) ans=sum+res;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}