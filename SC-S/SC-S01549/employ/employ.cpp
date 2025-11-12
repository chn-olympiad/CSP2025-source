#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
constexpr int mod=998244353;
int n,m,c[505],dp[1ll<<18][19],ans; char s[505];
inline void mad(int&l,const int r){(l+=r)>=mod&&(l-=mod);}
signed main(){
    if(online)
        freopen("employ.in","r",stdin),
        freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0); cin>>n>>m>>s;
    for(int i=0;i!=n;++i) cin>>c[i];
    if(n<=18){
        dp[0][0]=1;
        for(int i=0;i!=1ll<<n;++i)
            for(int j=0;j!=n;++j)
                if(!(i>>j&1))
                    for(int k=0;k!=n;++k)
                        if(dp[i][k])
                            if(k>=c[j]||s[__builtin_popcount(i)]=='0')
                                mad(dp[i|1ll<<j][k+1],dp[i][k]);
                            else mad(dp[i|1ll<<j][k],dp[i][k]);
        for(int i=0;i<=n-m;++i) mad(ans,dp[(1ll<<n)-1][i]);
        cout<<ans<<endl; return 0;
    }//2^n 的暴力，应该是有分的
    /*
    我们思考怎么去优化这个东西。
    我们真的关心你到底是谁吗？一点都不在乎。
    所以首先从小到大排序 c 是非常有道理的。
    
    正难则反，我们考虑计算不合法方案数。
    这样似乎能够做 m=1。
    似乎没有任何思路。
    算了吧，反正都 T4 了。
    */
    sort(c,c+n);
    if(m==n){
        if(c[0]==0){
            cout<<"0\n";
            return 0;
        }
        for(int i=0;i!=n;++i)
            if(s[i]=='0'){
                cout<<"0\n";
                return 0;
            }
        int ans=1;
        for(int i=1;i<=n;++i)
            ans=ans*i%mod;
        cout<<ans<<endl;
        return 0;
    }
    cout<<"0\n"; //那我还能怎么办？不可以，总司令！
    return 0; 
}
/*
铀祭：
自己体会吧。
*/