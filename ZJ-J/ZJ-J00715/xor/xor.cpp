#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e5 + 10;
LL a[N];
LL f[N];
LL n, k;
LL p[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]);
	memset(f, -1, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		f[i] = f[i - 1];
		int sum = a[i];
		for (int j = i - 1; j >= 0; j --)
		{
			if (sum == k)
			{
				f[i] = max(f[i], f[j] + 1);
				break;
			}
			sum ^= a[j];
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}
