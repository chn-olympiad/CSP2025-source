#include<bits/stdc++.h>
using namespace std;using ll=long long;
const int N=502,MOD=998244353;int n,m,s[N],c[N];
namespace T1_5{
	int dp[(1<<18)][22];
	inline void solve(){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)for(int k=0;k<=n;k++){
			int _i=0;
			for(int j=0;j<n;j++)_i+=((i>>j)&1);
			for(int j=0;j<n;j++)if(!((i>>j)&1))(dp[i^(1<<j)][k+(c[j+1]<=k||(!s[_i+1]))]+=dp[i][k])%=MOD;
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)(ans+=dp[(1<<n)-1][i])%=MOD;
		cout<<ans<<"\n";
	}
}
namespace T15{
	inline void solve(){
		ll ans=1;
		for(int i=1;i<=n;i++)(ans*=i)%=MOD;
		for(int i=1;i<=n;i++)if(!s[i])ans=0;
		for(int i=1;i<=n;i++)if(!c[i])ans=0;
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){char c;cin>>c,s[i]=(c^48);}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m)T15::solve();
	else if(n<=18)T1_5::solve();
	else cout<<"0\n";
	return 0;
}