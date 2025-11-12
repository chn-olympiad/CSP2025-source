#include <bits/stdc++.h>
using namespace std;
const long long N=1e4+20;
long long n,m,k,u,v,w,c[20],a[20][N],ans=1e18;
struct edge{
    long long u,v,w;
    bool operator<(const edge&other)const{
        return w<other.w;
    }
};
struct dsu{
    long long n,fa[N];
    void init(long long size){
        n=size;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
    }
    long long find(long long u){
        return fa[u]==u ? u : fa[u]=find(fa[u]);
    }
    void merge(long long u,long long v){
        fa[find(u)]=find(v);
    }
    bool same(long long u,long long v){
        return find(u)==find(v);
    }
}dd;
long long ku(long long n,vector<edge> &v){
    sort(v.begin(),v.end());
    dd.init(n);
    long long res=0,cnt=0;
    for(edge e:v){
        if(!dd.same(e.u,e.v)){
            res+=e.w;
            cnt++;
            dd.merge(e.u,e.v);
            if(cnt==n-1){
                break;
            }
        }
    }
    return res;
}
vector<edge> adj;
bool flag1=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]){
            flag1=0;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    long long s=0;
    if(flag1){
        s=(1<<k)-1;
    }
    for(int i=s;i<(1<<k);i++){
        vector<edge> adj1=adj;
        long long n1=n,res=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                n1++;
                res+=c[j];
                for(int kk=1;kk<=n;kk++){
                    adj1.push_back({n1,kk,a[j][kk]});
                }
            }
        }
        res+=ku(n1,adj1);
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
    return 0;
}