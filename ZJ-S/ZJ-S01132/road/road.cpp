#include<bits/stdc++.h>
#define For(i,il,ir) for(int i=(il);i<=(ir);i++)
#define Rof(i,ir,il) for(int i=(ir);i>=(il);i--)
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int maxn=1e4+10;
const int maxm=1e6+20;

int n,m,K;
struct edge{
    int u,v;ll w;
}e[maxm];

ll c[12],res;
vector<pli> ve[12];

int fa[maxn];
int fd(int x){
    while(x^fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

int id[12],p[12];

signed main()
{
    // double st=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&K);
    For(i,1,m) scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    For(i,1,K){
        scanf("%lld",&c[i]);
        For(j,1,n){
            ll val;scanf("%lld",&val);
            ve[i].push_back(make_pair(val,j));
        }
        sort(ve[i].begin(),ve[i].end());
    }

    For(i,1,n) fa[i]=i;
    sort(e+1,e+1+m,[&](edge xx,edge yy){ return xx.w<yy.w; });
    int et=0;
    For(i,1,m)
    {
        int fx=fd(e[i].u),fy=fd(e[i].v);
        if(fx==fy) continue;
        fa[fx]=fy; 
        res+=e[i].w;
        e[++et]=e[i];
        if(et==n-1) break;
    }
    m=n-1,e[n].w=0x3f3f3f3f3f3f3f3f;
    
    For(S,1,(1<<K)-1)
    {
        ll sum=0; int ct=0;
        For(i,1,K) if(S>>(i-1)&1) id[++ct]=i,p[ct]=0,sum+=c[i];
        For(i,1,n+ct) fa[i]=i;
        
        p[0]=1;
        For(et,1,n+ct-1)
        {
            while(p[0]<n && fd(e[p[0]].u)==fd(e[p[0]].v)) p[0]++;
            int mn=0; ll val=e[p[0]].w;

            For(i,1,ct){
                while(p[i]<n && fd(ve[id[i]][p[i]].second)==fd(i+n)) p[i]++;
                if(p[i]<n && ve[id[i]][p[i]].first<val)
                    val=ve[id[i]][p[i]].first,mn=i;
            }
            int fx,fy;
            if(mn==0) fx=fd(e[p[0]].u),fy=fd(e[p[0]].v);
            else fx=fd(mn+n),fy=fd(ve[id[mn]][p[mn]].second);
            fa[fx]=fy,sum+=val,p[mn]++;
        }
        res=min(res,sum);
    }
    printf("%lld\n",res);
    // double ed=clock();
    // double tm=(ed-st)/CLOCKS_PER_SEC;
    // cerr<<tm<<endl;
    // printf("%.3lf\n",tm);
    return 0;
}