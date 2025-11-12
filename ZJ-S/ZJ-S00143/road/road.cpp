//2025CSP-S RP++
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 10003
struct edge{
    int from,to,w,nxt;
}e[2200100];
using namespace std;
int n,m,k,tot,c[15],fa[N+20],du[N],ans;//head[N+20];
void ade(int u,int v,int w)
{
    e[++tot].to=v;
    e[tot].from=u;
    //e[tot].nxt=head[u];
    e[tot].w=w;
    //head[u]=tot;
    return ;
}
int fd(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=fd(fa[x]);
}
bool cmp(edge x,edge y){return x.w<y.w;}
void kruskal()
{
    for(int i=1;i<=tot;i++)
    {
        if(e[i].from==0) continue;
        fa[e[i].to]=fd(fa[e[i].to]);
        fa[e[i].from]=fd(fa[e[i].from]);
        if(fa[e[i].to]!=fa[e[i].from])
        {
            fa[e[i].to]=fa[e[i].from];
            ans+=e[i].w;
            if(e[i].from>n+10&&e[i].to<=n)
            {
                ++du[e[i].from];
            }
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ade(u,v,w);
        ade(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        ade(n+i,n+10+i,c[i]);// v point and cs point
        for(int j=1;j<=n;++j)
        {
            fa[j]=j;
            int a;
            scanf("%d",&a);
			ade(j,n+i,0);
            ade(n+10+i,j,a);//cs point and city point
        }
    }
    sort(e+1,e+tot+1,cmp);
    kruskal();
    for(int i=n+10+1;i<=n+10+k;++i)
    {
        if(du[i]==0) ans-=c[i];
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
