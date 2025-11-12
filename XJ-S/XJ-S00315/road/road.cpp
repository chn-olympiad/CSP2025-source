#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;
const int N=1e4+100;
struct node
{
    LL u,v,w;
};

LL n,m,k;
LL c[N];
vector<node> mp;
bool cmp(node x,node y){
    return x.w<y.w;
}
LL fa[N];
LL ans;
LL findfa(LL x){
    if(fa[x]==x) return x;
    else return fa[x]=findfa(fa[x]);
}
void unite(LL x,LL y){
    int fax=findfa(x),fay=findfa(y);
    fa[fax]=fay;
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(LL i=1;i<=m;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        mp.push_back({u,v,w});
    }
    for(LL i=1;i<=n+k;i++)
        fa[i]=i;
    for(LL i=1;i<=k;i++){
        cin>>c[i];
        for(LL j=1;j<=n;j++){
            LL w;
            cin>>w;
            if(i)mp.push_back({i+n,j,w});
        }
    }
    sort(mp.begin(),mp.end(),cmp);
    for(auto q:mp){
        LL u=q.u,v=q.v,w=q.w;
        LL fau=findfa(u),fav=findfa(v);
        if(fau==fav) continue;
        unite(u,v);
        ans+=w;
    }
    cout<<ans;
    return 0;
}