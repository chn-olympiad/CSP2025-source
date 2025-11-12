#include<bits/extc++.h>
#define cir(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("replace.in");
ofstream ouf("replace.out");
template<typename _Ty,const _Ty c>
class hashbase{
private:
    vector<_Ty> h,pw;
    auto init(string s){
        for(auto uh=(_Ty)(0);auto&x:s){
            (uh*=c)+=x;
            h.emplace_back(uh);
        }
        pw.resize(s.size()+7,1);
        cir(i,1,(int)(pw.size())) pw[i]=pw[i-1]*c;
    }
public:
    auto substr(int l,int r){
        return h[r]-(l?h[l-1]:0)*pw[r-l+1];
    }
    auto power(auto x){
        return pw[x];
    }
    hashbase(string s){init(s);}
};
static constexpr auto maxl=(int)(5e6+7);
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int n,q;inf>>n>>q;
    vector<__gnu_pbds::gp_hash_table<uint64_t,int>> cnt(maxl);
    vector<int> ul;
    cir(i,0,n){
        string s,t;inf>>s>>t;
        const auto l=(int)(s.size());
        ul.emplace_back(l);
        ++cnt[l][hashbase<uint64_t,251>(s+t).substr(0,l*2-1)];
    }
    sort(ul.begin(),ul.end());
    ul.erase(unique(ul.begin(),ul.end()),ul.end());
    cir(i,0,q){
        string s,t;inf>>s>>t;
        const auto l=(int)(s.size());
        auto pl=0,pr=l-1;
        while(s[pl]==t[pl]) ++pl;
        while(s[pr]==t[pr]) --pr;
        const auto req=pr-pl+1;
        const auto lb=lower_bound(ul.begin(),ul.end(),req)-ul.begin();
        const auto rb=upper_bound(ul.begin(),ul.end(),l)-ul.begin();
        hashbase<uint64_t,251> hs(s),ht(t);
        auto ans=0ll;
        cir(i,lb,rb){
            const auto cl=ul[i];
            const auto pw=ht.power(cl);
            const auto rl=max(pl-(cl-req),0);
            const auto rr=min(pl,l-cl);
            cir(i,rl,rr+1) if(cnt[cl].find(hs.substr(i,i+cl-1)*pw+ht.substr(i,i+cl-1))!=cnt[cl].end()){
                ans+=cnt[cl][hs.substr(i,i+cl-1)*pw+ht.substr(i,i+cl-1)];
            }
        }
        ouf<<ans<<'\n';
    }
    return 0;
}
