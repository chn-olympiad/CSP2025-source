#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 505;
const int mod = 998244353;
int n, m, p[maxN];
char flag[maxN];
ll ans;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", flag + 1);
	for (int i = 1; i <= n; i++) { scanf("%d", &p[i]); }
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = ans * i % mod;
	}
	printf("%lld", ans);
	return 0;
}
