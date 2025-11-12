#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;

int n,m,ans,c[510],p[510];
char s[510];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s + 1);
	for (int i = 1;i <= n;i++) scanf("%lld",&c[i]),p[i] = i;
	if (n > 20)
	{
		ans = 1;
		for (int i = 1;i <= n;i++) ans = ans * i % mod;
		printf("%lld\n",ans);
		return 0;
	}
	do
	{
		int cnt = 0;
		for (int i = 1;i <= n;i++) if (i - cnt - 1 < c[p[i]] && s[i] == '1') if ((++cnt) >= m) break;
		ans += (cnt >= m);
	}while (next_permutation(p + 1,p + n + 1));
	printf("%lld\n",ans);
	return 0;
}
