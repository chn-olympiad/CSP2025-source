#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T,n,ans=-1;
int a[N][4],cnt[3];
void dfs(int de,int sum) {
	if(de==n+1) {
		ans=max(ans,sum);
		return ;
	}
	for(int i=1; i<=3; i++) {
		if(cnt[i]<n/2) {
			cnt[i]++;
			dfs(de+1,sum+a[de][i]);
			cnt[i]--;
		}
	}
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%lld",&T);
	while(T--) {
		ans=-1;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%lld",&a[i][j]);
			}
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

