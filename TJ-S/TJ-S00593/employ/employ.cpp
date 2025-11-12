#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[505], p[505];
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = i;
	}
	s = " " + s;
	long long ans = 0;
	do
	{
		long long cnt = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
//			cout << a[i] << " ";
			if (sum < a[p[i]] && s[i] == '1') cnt++;
			if (sum >= a[p[i]]) sum++;
			sum += (s[i] == '0');

		}
//		cout << endl;
//		cout << cnt << endl;
		if (cnt >= m) ans++;
		ans %= 998244353; 
 	}while(next_permutation(p + 1, p + n + 1));
 	cout << ans << endl;
 	return 0;
} 
