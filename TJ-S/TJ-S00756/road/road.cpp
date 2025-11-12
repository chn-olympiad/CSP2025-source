#include<bits/stdc++.h>
using namespace std;
namespace Main{
using lnt=long long;
const int N=1e4+10,M=1e6+10,K=15;
int n,m,k,h[N];lnt ans=0x3f3f3f3f3f3f3f3f;
struct edge{int u,v;lnt w;};vector<edge>dat,mdat;
struct node{lnt cost;vector<lnt>edges;}apd[K];
class UFS{
    int fa[N];
public:
    void init(){for(int i=1;i<=n+k+1;i++)fa[i]=i;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int a,int b){fa[find(a)]=find(b);}
    bool full(){
        for(int i=2;i<=n;i++)if(find(i)!=find(1))return false;
        return true;
    }
}ufs;
lnt proc(int s){lnt res=0;
    vector<edge>proc=mdat;ufs.init();
    for(int i=0;i<k;i++){
        if((s>>i)&1){
            res+=apd[i].cost;
            for(int j=1;j<=n;j++){
                proc.push_back({n+i+1,j,apd[i].edges[j]});
            }
        }
    }
    sort(proc.begin(),proc.end(),[](edge a,edge b){return a.w<b.w;});
    int cnt=0;
    for(edge p:proc){
        if(ufs.find(p.u)!=ufs.find(p.v)){
            cnt++;
            res+=p.w;
            ufs.merge(p.u,p.v);
        }
    }//cerr<<cnt<<'\n';
    return ufs.full()?res:0x3f3f3f3f3f3f3f3f;
}
void main(){
    scanf("%d%d%d",&n,&m,&k);ufs.init();ans=0;
    for(int i=0;i<m;i++){edge tmp;
        scanf("%d%d%lld",&tmp.u,&tmp.v,&tmp.w);dat.push_back(tmp);
    }
    sort(dat.begin(),dat.end(),[](edge a,edge b){return a.w<b.w;});
    for(edge p:dat){
        if(ufs.find(p.u)!=ufs.find(p.v)){
            ans+=p.w;mdat.push_back(p);
            ufs.merge(p.u,p.v);
        }
    }//cerr<<mdat.size()<<' ';
    for(int i=0;i<k;i++){
        scanf("%lld",&apd[i].cost);apd[i].edges.push_back(0x3f3f3f3f3f3f3f3f);
        //cerr<<apd[i].cost<<'\n';
        for(int j=1;j<=n;j++){
            lnt t;scanf("%lld",&t);
            apd[i].edges.push_back(t);
        }
    }
    for(int i=1;i<(1<<k);i++){
        lnt res=proc(i);
        ans=min(ans,res);
    }printf("%lld",ans);
}
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    Main::main();
    return 0;
}
