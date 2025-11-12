#include<bits/stdc++.h>
using namespace std;
const int N=500005,mod=998244353;
int dp[N][20],n,m,c[N];
char s[30];
int pop[N];
int bul[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0; i<n; i++)
		scanf("%d",c+i);
	dp[0][0]=1;
	if(n<=18) {
		for(int st=0; st<(1<<n); st++) {
			pop[st]=pop[st>>1]+(st&1);
			for(int j=0; j<n; j++) {
				if(st&1<<j)continue;
				for(int k=0; k<n; k++) {
					if(k>=c[j] || s[pop[st]]=='0')
						dp[st|1<<j][k+1] += dp[st][k];
					else
						dp[st|1<<j][k] +=dp[st][k];
				}
			}
			//cout<<dp[st][0]<<" "<<dp[st][1]<<" "<<dp[st][2]<<" "<<dp[st][3]<<endl;
		}
		int ans=0;
		for(int i=0; i<=n-m; i++) {
			ans+=dp[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans;
		return 0;

	}
	return 0;
}

