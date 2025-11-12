#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=20005;
LL n,m,k,f[N],c[15],an=1e18;
struct nd{LL x,y,z;};vector<nd>v1,v3,v2[15];
LL fd(LL x){return x==f[x]?x:f[x]=fd(f[x]);}
bool cmp(nd u,nd v){return u.z<v.z;}
void dfs(vector<nd>vc,LL nw,LL sm){
    if(nw>k){
        for(auto i:vc)sm+=i.z;
        an=min(an,sm);
        return;
    }
    dfs(vc,nw+1,sm);
    for(LL i=1;i<=n+k;++i)f[i]=i;
    LL u=0,v=0;vector<nd>l={};
    while(u<vc.size()&&v<v2[nw].size())
    if(vc[u].z<v2[nw][v].z){
        if(fd(vc[u].x)!=fd(vc[u].y))f[fd(vc[u].x)]=fd(vc[u].y),l.push_back(vc[u]);
        ++u;
    }else{
        if(fd(v2[nw][v].x)!=fd(v2[nw][v].y))f[fd(v2[nw][v].x)]=fd(v2[nw][v].y),l.push_back(v2[nw][v]);
        ++v;
    }
    while(u<vc.size()){
        if(fd(vc[u].x)!=fd(vc[u].y))f[fd(vc[u].x)]=fd(vc[u].y),l.push_back(vc[u]);
        ++u;
    }
    while(v<v2[nw].size()){
        if(fd(v2[nw][v].x)!=fd(v2[nw][v].y))f[fd(v2[nw][v].x)]=fd(v2[nw][v].y),l.push_back(v2[nw][v]);
        ++v;
    }
    dfs(l,nw+1,sm+c[nw]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(LL i=1;i<=n;++i)f[i]=i;
    for(LL x,y,z;m--;)cin>>x>>y>>z,v1.push_back({x,y,z});
    sort(v1.begin(),v1.end(),cmp);
    for(auto i:v1)if(fd(i.x)!=fd(i.y))f[fd(i.x)]=fd(i.y),v3.push_back(i);
    for(LL i=1;i<=k;++i){
        cin>>c[i];
        for(LL j=1,z;j<=n;++j)cin>>z,v2[i].push_back({n+i,j,z});
        sort(v2[i].begin(),v2[i].end(),cmp);
    }
    dfs(v3,1,0);
    cout<<an;return 0;
}