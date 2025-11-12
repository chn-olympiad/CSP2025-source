#include<bits/stdc++.h>
#define cir(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("road.in");
ofstream ouf("road.out");
using lint=long long;
class dsu{
private:
    vector<int> f;
public:
    auto findset(int u)->int{
        return f[u]==u?u:f[u]=findset(f[u]);
    }
    auto merge(int u,int v){
        f[findset(u)]=findset(v);
    }
    dsu(int _n):f(_n){iota(f.begin(),f.end(),0);}
};
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int n,m,k;inf>>n>>m>>k;
    vector<tuple<int,int,lint>> es;
    vector<vector<int>> prk(k);
    es.reserve(m+n*k);
    cir(i,0,m){
        int u,v;lint w;inf>>u>>v>>w;--u;--v;
        es.emplace_back(u,v,w);
    }
    vector<lint> uw(k);
    cir(i,0,k){
        inf>>uw[i];
        cir(j,0,n){
            lint w;inf>>w;
            prk[i].emplace_back(es.size());
            es.emplace_back(i+n,j,w);
        }
    }
    vector<int> mst;
    auto ans=0ll;
    auto mst_cmp=[&](auto&a,auto&b){
        return get<2>(es[a])<get<2>(es[b]);
    };
    [&]{
        vector<int> sp(m);
        iota(sp.begin(),sp.end(),0);
        dsu qwq(n);
        sort(sp.begin(),sp.end(),mst_cmp);
        for(auto&eid:sp){
            const auto&[u,v,w]=es[eid];
            if(qwq.findset(u)!=qwq.findset(v)){
                qwq.merge(u,v);
                mst.emplace_back(eid);
                ans+=w;
            }
        }
    }();
    for(auto&x:prk) sort(x.begin(),x.end(),mst_cmp);
    vector<vector<int>> stc;
    vector<int> nstc,nstc_info;
    stc.emplace_back(mst);
    auto dfs=[&](auto __self,int r,lint ad){
        if(r==k) return;
        stc.emplace_back(stc.back());
        __self(__self,r+1,ad);
        stc.pop_back();
        nstc_info.clear();
        nstc_info.resize(stc.back().size()+prk[r].size());
        merge(stc.back().begin(),stc.back().end(),prk[r].begin(),prk[r].end(),nstc_info.begin(),mst_cmp);
        nstc.clear();
        dsu qwq(n+k);
        auto uans=ad+uw[r];
        for(auto&eid:nstc_info){
            const auto&[u,v,w]=es[eid];
            if(qwq.findset(u)!=qwq.findset(v)){
                qwq.merge(u,v);
                nstc.emplace_back(eid);
                uans+=w;
            }
        }
        ans=min(ans,uans);
        stc.emplace_back(nstc);
        __self(__self,r+1,ad+uw[r]);
        stc.pop_back();
    };
    dfs(dfs,0,0);
    ouf<<ans<<'\n';
    return 0;
}
