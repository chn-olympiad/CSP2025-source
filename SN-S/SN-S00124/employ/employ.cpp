#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,m,ans,c[105],dp[1<<19][25];
char s[105];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>(s+1),dp[0][0]=1;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int S=0;S<1<<n;S++){
		for(int i=0;i<=n;i++){
			if(!dp[S][i]) continue;
			for(int j=1;j<=n;j++){
				if(S>>(j-1)&1) continue;
				int flg=(i>=c[j]||s[__builtin_popcount(S)+1]=='0');
				(dp[S|(1<<(j-1))][i+flg]+=dp[S][i])%=mod;
			}
		}
	}
	for(int i=m;i<=n;i++) (ans+=dp[(1<<n)-1][n-i])%=mod;
	cout<<ans<<'\n';
	return 0;
}
