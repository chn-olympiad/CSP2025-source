#include <iostream>
using namespace std;
char c[510];
int s[510];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		s[c]++;
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= (long long)i;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
