#include<bits/stdc++.h>
using namespace std;
#define NOIIO
// #define MULTI_CASES
#define ll long long 
#define int ll
#define endl '\n'
#define vi vector<int>
#define PII pair<int,int>
const int MaxN=4e5+100;
const int INF=1e9;
const int mod=998244353;
int N,M,T=1;
int a[MaxN];
inline void Solve(){
    cin>>N>>M;
    int ans=1;
    for(int i=1;i<=N;i++){
        (ans*=i)%=mod;
    }
    cout<<ans%mod<<endl;
}
signed main(){
#ifdef NOIIO
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#ifdef MULTI_CASES
    cin>>T;
    while(T--)
#endif
        Solve();
    return 0;
}