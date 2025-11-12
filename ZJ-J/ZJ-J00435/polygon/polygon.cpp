#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5,P=998244353;
int n,a[N];
ll ans,sum[N][N];
//deque<int> dq;
void dfs(int x,int cnt,ll sum,int lt) {
	if (x>n) {
		if (sum>a[lt]*2&&cnt>=3) {
			ans=(ans+1LL)%P;
//			for (auto v:dq)
//				printf("%d ",v);
//			printf("\n");
		}
		return;
	}
	if (cnt+n-x+1<3) return;
	dfs(x+1,cnt,sum,lt);
//	dq.push_back(x);
	dfs(x+1,cnt+1,sum+a[x],x);
//	dq.pop_back();
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n<3) {
		printf("0\n");
		return 0;
	}
	sort(a+1,a+n+1);
	if (n==3) {
		if (a[1]+a[2]>a[3])
			printf("1\n");
		else printf("0\n");
		return 0;
	}
	if (a[n]==1) {
		sum[1][1]=1LL;
		for (int i=0;i<=n;i++)
			sum[i][0]=1LL;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=i;j++)
				sum[i][j]=(sum[i-1][j]+sum[i-1][j-1])%P;
		for (int i=3;i<=n;i++)
			ans=(ans+sum[n][i])%P;
		printf("%lld\n",ans);
		return 0;
	}
	dfs(1,0,0LL,0);
	printf("%lld\n",ans);
	return 0;
}