#include <cstdio>
#include <algorithm>
namespace force {
	const int MOD=998244353;
	const int N=21;
	int n;
	int a[N];
	int dfs(int now,int sum,int maxv,int cnt) {
		if (now>n) return (cnt>=3 && sum>2*maxv);
		int ans=0;
		ans=(ans+dfs(now+1,sum,maxv,cnt))%MOD;
		ans=(ans+dfs(now+1,sum+a[now],std::max(maxv,a[now]),cnt+1))%MOD;
		return ans;
	}
	void solve() {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		printf("%d\n",dfs(1,0,0,0));
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	force::solve();
	return 0;
}
