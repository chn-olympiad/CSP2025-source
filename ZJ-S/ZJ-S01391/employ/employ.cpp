#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
constexpr int maxn=510,maxpos=18,mod=998244353;
bool b[maxn];
int c[maxn],js[maxn];
struct presolve{
    presolve(){
        js[0]=1;
        for(int i=1;i<maxn;i++){
            js[i]=1ll*js[i-1]*i%mod;
        }
    }
}presolve;
int n,m;
namespace Sub2{

    int f[1<<maxpos][maxpos+1];
    void solve(){
        f[0][0]=1;
        for(int S=1;S<(1<<n);S++){
            int maxs=__builtin_popcount(S);
            for(int cnt=0;cnt<=maxs;cnt++){
                for(int i=1;i<=n;i++){
                    if((S>>(i-1))&1){
                        int pos=(S^(1<<(i-1)));
                        if(maxs-1-(cnt-1)<c[i] and !b[maxs] and cnt){
                            f[S][cnt]+=f[pos][cnt-1];
                            if(f[S][cnt]>=mod)f[S][cnt]-=mod;
                        }
                        if(maxs-1-cnt>=c[i] or b[maxs]){
                            f[S][cnt]+=f[pos][cnt];
                            if(f[S][cnt]>=mod)f[S][cnt]-=mod;
                        }
                    }
                }
                // debug1(S);debug1(cnt);debug2(f[S][cnt]);
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            ans+=f[(1<<n)-1][i];
            if(ans>=mod)ans-=mod;
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        b[i]=(c=='0');
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        Sub2::solve();
        return 0;
    }
    if(m==n){
        bool ok=1;
        for(int i=1;i<=n;i++)ok=ok and (!(b[i]));
        for(int i=1;i<=n;i++)ok=ok and (c[i]!=0);
        if(ok)cout<<js[n]<<"\n";
        else cout<<"0\n";
        return 0;
    }
    cout<<js[n]<<"\n";
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/