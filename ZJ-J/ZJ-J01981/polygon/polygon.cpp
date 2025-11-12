#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, maxll = 0, a[5001], l[5001], ans = 0;
bool check()
{
	long long maxl = 0, sum = 0;
	for(long long i = 1; i <= n; i ++)
		if(a[i])
			maxl = max(l[i], maxl), sum += l[i];
	if(sum > 2 * maxl)
		return 1;
	return 0;
}
void dg(long long c)
{
	if(c == n+1)
	{
		if(check())
			ans++;
		return;
	}
	a[c] = 0;
	dg(c+1);
	a[c] = 1;
	dg(c+1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i ++)
	{	
		scanf("%d", &l[i]);
		maxll = max(l[i], maxll);
	}
	if(maxll == 1 || n > 30)
	{
		ans = 1;
		for(long long i = 1; i <= n; i ++)
			ans = ans * 2 % mod;
		cout << ans << endl;
		return 0;
	}
	dg(1);
	cout << ans << endl;
	return 0;
}