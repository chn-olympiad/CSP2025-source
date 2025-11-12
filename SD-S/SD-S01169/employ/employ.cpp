#include<bits/stdc++.h>
using namespace std;
const int N=25,mod=998244353;
int dp[270000][N],n,m,c[N],ans;
char s[N+10];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>18) {
		printf("0\n");
		return 0;
	}
	scanf("%s",&s[1]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dp[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++) {
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=(1&(i>>j-1));
		for(int j=1;j<=n;j++) {
			for(int k=0;k<=cnt;k++) {
				if(!(1&(i>>j-1))) {
					if(cnt-k>=c[j]||s[cnt+1]=='0') {
						dp[i|(1<<j-1)][k]+=dp[i][k];
						if(dp[i|(1<<j-1)][k]>=mod) dp[i|(1<<j-1)][k]-=mod;
					} else {
						dp[i|(1<<j-1)][k+1]+=dp[i][k];
						if(dp[i|(1<<j-1)][k+1]>=mod) dp[i|(1<<j-1)][k+1]-=mod;
					}
				}
			}
		}
	}
	for(int i=m;i<=n;i++) {
		ans+=dp[(1<<n)-1][i];
		if(ans>=mod) ans-=mod;
	}
	printf("%d\n",ans);
	return 0;
}

