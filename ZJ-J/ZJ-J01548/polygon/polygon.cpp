#include<bits/stdc++.h>
using namespace std;
int n, a[5010], unsuc[5010], f[5010];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 5001; j >= a[i] + 1; j--)
			if(f[j] > 0)
				f[min(5001, j + a[i])] += f[j];
		for(int j = 5001; j >= a[i] + 1; j--)
			if(unsuc[j] > 0)
				f[min(5001, j + a[i])] += unsuc[j];
		for(int j = a[i]; j >= 1; j--)
			if(f[j] > 0)
				unsuc[min(5001, j + a[i])] += f[j];
		for(int j = a[i]; j >= 1; j--)
			if(unsuc[j] > 0)
				unsuc[min(5001, j + a[i])] += unsuc[j];
		for(int j = 1; j < i; j++)
			unsuc[min(5001, a[j] + a[i])]++;
	}
	for(int i = 1; i <= 5001; i++)
		ans += f[i], ans %= 998244353;
	cout << ans;
	return 0;
}