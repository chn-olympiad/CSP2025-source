#include<bits/stdc++.h>
using namespace std;

// #define int ll
#define file(jzc) freopen(#jzc".in","r",stdin),freopen(#jzc".out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound
#define UB upper_bound
#define all(a) (a).begin(),(a).end()

using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using vi=vector<int>;
using vvi=vector<vi>;

template<typename T1,typename T2>
void chkmin(T1&x,const T2&y){if(y<x)x=y;}
template<typename T1,typename T2>
void chkmax(T1&x,const T2&y){if(x<y)x=y;}

struct{
    int fa[10100];
    void init(int n){fill(fa,fa+n+1,-1);}
    int getfa(int x){return fa[x]<0?x:fa[x]=getfa(fa[x]);}
    bool merge(int x,int y){
        x=getfa(x),y=getfa(y);
        if(x==y)return 0;
        if(fa[x]>fa[y])swap(x,y);
        fa[x]+=fa[y],fa[y]=x;
        return 1;
    }
}dsu;

struct E{
    int u,v,w;
    bool operator<(const E&a)const{return w<a.w;}
};

ll ans;
int n,m,k;
vector<E>w[12];
int c[12];

vector<E>getjzc(const vector<E>&ed){
    vector<E>res;
    dsu.init(n+15);
    for(auto[u,v,w]:ed)dsu.merge(u,v)&&(res.pb({u,v,w}),0);
    return res;
}

void dfs(int x,ll sm,vector<E>ed){
    if(x>=k){
        for(auto[u,v,w]:ed)sm+=w;
        chkmin(ans,sm);
        return;
    }
    dfs(x+1,sm,ed);
    for(auto jzcjzc:w[x])ed.pb(jzcjzc);
    inplace_merge(ed.begin(),ed.end()-n,ed.end());
    dfs(x+1,sm+c[x],getjzc(ed));
}

void solve(){
    cin>>n>>m>>k;
    vector<E>e(m);
    for(int i=0,u,v,w;i<m;i++)cin>>u>>v>>w,e[i]={u,v,w};
    for(int i=0;i<k;i++){
        w[i].resize(n);
        cin>>c[i];
        for(int j=0,jzc;j<n;j++)cin>>jzc,w[i][j]={n+i+1,j+1,jzc};
        sort(all(w[i]));
    }
    sort(all(e)),e=getjzc(e);
    ans=LONG_LONG_MAX;
    dfs(0,0,e);
    cout<<ans<<'\n';
}

signed main(){
    file(road);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
}

/*
17:41 pass all pretests and a big sample
*/