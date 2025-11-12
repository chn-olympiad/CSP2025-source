#include<bits/stdc++.h>
#define cir(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("employ.in");
ofstream ouf("employ.out");
using lint=long long;
static constexpr auto MOD=998244353;
class mathbase{
private:
    vector<lint> fct,ifct;
public:
    constexpr auto qpow(lint a,auto b) const{
        auto res=1ll;
        while(b){
            if(b&1) (res*=a)%=MOD;
            (a*=a)%=MOD;b>>=1;
        }
        return res;
    }
    constexpr auto inv(auto x) const{
        return qpow(x,MOD-2);
    }
    auto init(const int n){
        fct.resize(n,1);
        cir(i,1,n) fct[i]=fct[i-1]*i%MOD;
        ifct=fct;
        for(auto&x:ifct) x=inv(x);
    }
    constexpr auto A(auto a,auto b) const{
        return fct[a]*ifct[a-b]%MOD;
    }
    constexpr auto C(auto a,auto b) const{
        return fct[a]*ifct[b]%MOD*ifct[a-b]%MOD;
    }
} math;
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int n,m;inf>>n>>m;
    math.init(n+7);
    string s;inf>>s;
    vector<int> c(n);
    for(auto&i:c) inf>>i;
    vector<int> users(n+1);
    for(auto&x:c) ++users[x];
    vector<vector<lint>> f(n+1,vector<lint>(n+1));
    vector<vector<lint>> g(n+1,vector<lint>(n+1));
    f[0][0]=1;
    auto puser=users;
    cir(i,1,n+1) puser[i]+=puser[i-1];
    cir(i,0,n){
        swap(f,g);
        for(auto&x:f) fill(x.begin(),x.end(),0);
        if(s[i]=='1'){
            cir(a,0,n+1) cir(b,0,n+1) if(g[a][b]){
                // 1. 选择一个 give-up 的选手
                const auto cnt=puser[a]-(i-b);
                if(cnt<0||b>(n-puser[a])) continue;
                cir(c,0,min(users[a+1],b)+1) (f[a+1][b-c]+=g[a][b]*math.A(users[a+1],c)%MOD*math.C(b,c)%MOD*cnt%MOD)%=MOD;
                // 2. 选择一个可以放置的选手
                (f[a][b+1]+=g[a][b])%=MOD;
            }
        }else{
            cir(a,0,n+1) cir(b,0,n+1) if(g[a][b]){
                // 1. 选择一个 < A give-up 的选手
                const auto cnt=puser[a]-(i-b);
                if(cnt<0||b>(n-puser[a])) continue;
                cir(c,0,min(users[a+1],b)+1) (f[a+1][b-c]+=g[a][b]*math.A(users[a+1],c)%MOD*math.C(b,c)%MOD*cnt%MOD)%=MOD;
                // 2. 选择一个 > A give-up 的选手
                cir(c,0,min(users[a+1],b)+1) (f[a+1][b-c+1]+=g[a][b]*math.A(users[a+1],c)%MOD*math.C(b,c)%MOD)%=MOD;
                // 2. 选择一个 = A give-up 的选手
                cir(c,1,min(users[a+1],b+1)+1) (f[a+1][b-c+1]+=g[a][b]*math.A(users[a+1],c)%MOD*math.C(b,c-1)%MOD)%=MOD;
            }
        }
    }
    auto ans=0ll;
    cir(a,0,n-m+1) cir(b,0,n+1){
        const auto cnt=puser[a]-(n-b);
        if(cnt<0||b>(n-puser[a])) continue;
        (ans+=f[a][b]*math.A(b,b))%=MOD;
    }
    ouf<<ans<<'\n';
    return 0;
}
/*
我常常追忆过去。

生命的瞬间定格在我的脑海，我将背后的时间裁减，弯曲，揉捏成天上朵朵白云。

云朵之间亦有分别，积云厚重，而卷云飘渺，....

...

过去已经凝固，我带着回忆向前，只是时常疏于保管，追忆也在改变着各自的形态，这给我的追忆旅程带来些许挑战。

我该在哪里停留，我问我自己。
*/