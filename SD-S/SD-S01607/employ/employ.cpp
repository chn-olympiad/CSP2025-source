#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[20],dp[1<<18][19],mod=998244353;
char a[20];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int cnt=0;
		for(int i=1;i<=n;i++)if((s>>i-1)&1)cnt++;
		for(int i=0;i<=m;i++){
			for(int j=1;j<=n;j++){
				if((s>>j-1)&1)continue;
				(dp[s|(1<<j-1)][i+((c[j]<=i)||(a[cnt+1]=='0'))]+=dp[s][i])%=mod;
			}
		}
	}
	cout<<dp[(1<<n)-1][n-m];
}
