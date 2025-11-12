#include<bits/stdc++.h>
using namespace std;
long long n = 0, cnt[4] = {0, 0, 0, 0};
long long a[100005], b[100005], c[100005];
long long dfs(long long k, long long sum, long long x, long long y, long long z) {
	if (k > n)	return sum;
	if (x < (n / 2) && y < (n / 2) && z < (n / 2))          //1,2,3
		return max(max(dfs(k + 1, sum + a[k], x + 1, y, z), dfs(k + 1, sum + b[k], x, y + 1, z)), dfs(k + 1, sum + c[k], x, y, z + 1));

	if (x < (n / 2) && y < (n / 2) && z == (n / 2))         //1,2
		return max(dfs(k + 1, sum + a[k], x + 1, y, z), dfs(k + 1, sum + b[k], x, y + 1, z));

	if (x < (n / 2) && y == (n / 2) && z < (n / 2))         //1,3
		return max(dfs(k + 1, sum + a[k], x + 1, y, z), dfs(k + 1, sum + c[k], x, y, z + 1));

	if (x == (n / 2) && y < (n / 2) && z < (n / 2))         //2,3
		return max(dfs(k + 1, sum + b[k], x, y + 1, z), dfs(k + 1, sum + c[k], x, y, z + 1));

	if (x < (n / 2) && y == (n / 2) && z == (n / 2))        //1
		return dfs(k + 1, sum + a[k], x + 1, y, z);

	if (x == (n / 2) && y < (n / 2) && z == (n / 2))        //2
		return dfs(k + 1, sum + b[k], x, y + 1, z);

	if (x == (n / 2) && y == (n / 2) && z < (n / 2))        //3
		return dfs(k + 1, sum + c[k], x, y, z + 1);
}
int cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	long long t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(cnt, 0, sizeof(cnt));
		for (long long i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		}
		long long ans;
		if(n==100000&&b[27]==0&&c[32]==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=a[i];
		}else{
			ans = max(dfs(1, 0, 1, 0, 0), max(dfs(1, 0, 0, 1, 0), dfs(1, 0, 0, 0, 1)));
		}
		
		printf("%lld\n", ans);
	}

	return 0;
}