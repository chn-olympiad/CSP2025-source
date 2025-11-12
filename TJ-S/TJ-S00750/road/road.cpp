#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ks,a[19][10009],c[19];
vector<pair<int,pair<int,int>>>e,zz;
vector<pair<int,pair<pair<int,int>,int>>>q,z;
int f[10019];
int findf(int x){
    return f[x]==x?x:f[x]=findf(f[x]);
}
void mere(int u,int v){
    u=findf(u),v=findf(v);
    if (u==v)return;
    f[u]=v;
}
bool same(int u,int v){
    return findf(u)==findf(v);
}
ll krus(){
    sort(e.begin(),e.end());
    ll ans=0;
    for (int i=1;i<=n+ks;i++)f[i]=i;
    for (int i=0;i<e.size();i++){
        int u=e[i].second.first,v=e[i].second.second,w=e[i].first;
        if (same(u,v))continue;
        //cout<<u<<" "<<v<<" "<<w<<"\n";
        ans+=w;
        q.push_back({w,{{u,v},0}});
        zz.push_back({w,{u,v}});
        mere(u,v);
    }
    return ans;
}
ll krut(){
    sort(zz.begin(),zz.end());
    ll ans=0;
    for (int i=1;i<=n+ks;i++)f[i]=i;
    for (int i=0;i<zz.size();i++){
        int u=zz[i].second.first,v=zz[i].second.second,w=zz[i].first;
        if (same(u,v))continue;
        ans+=w;
        mere(u,v);
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&ks);
    for (int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.push_back({w,{u,v}});
    }
    for (int i=1;i<=ks;i++){
        scanf("%d",&c[i]);
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    ll ans=krus();
    if (ks<=0){
        cout<<ans;
        return 0;
    }
    int ok=1;
    for (int i=1;i<=ks;i++)if (c[i]!=0)ok=0;
    if (ok){
        for (int i=1;i<=ks;i++){
            for (int j=1;j<=n;j++){
                e.push_back({a[i][j],{n+i,j}});
            }
        }
        cout<<krus();
        return 0;
    }
    //if (k<=5){
        e=zz;
        //cout<<ans<<"\n";
        for (int i=0;i<(1<<ks);i++){
            zz=e;
            ll r=0;
            for (int j=1;j<=ks;j++){
                if (i&(1<<(j-1))){
                    for (int k=1;k<=n;k++){
                        zz.push_back({a[j][k],{j+n,k}});
                    }
                    r+=c[j];
                }
            }
            //cout<<krut()<<" "<<r<<"\n";
            ans=min(ans,krut()+r);
        }
        cout<<ans;
    //}
    return 0;
}
