#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,INF=1e9;
int n,b[N],a[N][4],dp[205][205][205];
ll ans;
bool cmp(int x,int y) {
	return x>y;
}
void solve() {
	ans=0LL;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
	if (n<=200) {
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
				for (int k=0;k<=n;k++)
					dp[i][j][k]=0;
		dp[0][0][0]=0;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<=i;j++)
				for (int k=0;k<=i;k++) {
					if (j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if (k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if (j+k<i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
		}
		for (int j=0;j<=n/2;j++)
			for (int k=0;k<=n/2;k++) {
				if (n-k-j<=n/2)
					ans=max(ans,1LL*dp[n][j][k]);
			}
		printf("%lld\n",ans);
	} else {
		for (int i=1;i<=n;i++)
			b[i]=a[i][1];
		sort(b+1,b+n+1,cmp);
		for (int i=1;i<=n/2;i++)
			ans+=1LL*b[i];
		printf("%lld\n",ans);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}
