#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1.1e6+5,MOD=998244353;
int n,m;
int s[N],c[N];
vector<int> vec[25];
int f[N][25];
void sub1(){
    for(int S=0;S<(1<<n);++S)vec[__builtin_popcount(S)].push_back(S);
    f[0][0]=1;
    for(int i=0;i<n;++i){
        for(int S:vec[i]){
            for(int j=1;j<=n;++j){
                if(S&(1<<(j-1)))continue;
                int T=S|(1<<(j-1));
                for(int k=0;k<=i;++k){
                    int rej=i-k;
                    if(s[i+1]==0||rej>=c[j])(f[T][k]+=f[S][k])%=MOD;
                    else (f[T][k+1]+=f[S][k])%=MOD;
                }
            }
        }
    }
    int ans=0;
    for(int i=m;i<=n;++i)(ans+=f[(1<<n)-1][i])%=MOD;
    cout<<ans<<"\n";
}
int cnt[N];
void sub2(){
    for(int i=1;i<=n;++i){
        if(!s[i]||!c[i]){
            cout<<"0\n";
            return;
        }
    }
    int ans=1;
    for(int i=1;i<=n;++i)(ans*=i)%=MOD;
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        char ch;
        cin>>ch;
        s[i]=ch-'0';
    }
    for(int i=1;i<=n;++i)cin>>c[i];
    if(m==n){
        sub2();
        return 0;
    }
    if(n<=20){
        sub1();
        return 0;
    }
}