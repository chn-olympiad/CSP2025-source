#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e3 + 5;
const long long M = 998244353;
int n, a[N];
long long ans;
inline int read()
{
	int x=0, f=1; char ch = getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch = getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch = getchar();}
	return x * f;
}
void dfs(int dep, int sum, int maxn)
{
	if (dep == n+1)
	{
		if (sum > 2*maxn)
		{
			ans++;
			ans %= M;
		}
		return ;
	}
	dfs(dep+1, sum, maxn);
	dfs(dep+1, sum+a[dep],max(maxn, a[dep]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for (int i=1; i<=n; i++) a[i] = read();
	dfs(1, 0, 0);
	printf("%lld", ans);
	return 0;
}
