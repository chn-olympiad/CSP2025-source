#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],ans;
int solve(int a,int b)
{
	return (a + b) * (a - b + 1) / 2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	n -= 2;
	while(n > 0)
	{
		ans += solve(n,1);
		ans %= 998244353;
		//cout << solve(n,1) << " " << n << "\n";
		n--;
	}
	cout << ans;
	return 0;
}

