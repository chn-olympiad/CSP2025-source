#include <bits/stdc++.h>
#define ll long long
#define maxn 500005
using namespace std;

ll a[maxn];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);	
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		if (a[i] == k) ans++;
	}
	printf("%lld", ans);
	return 0;
}