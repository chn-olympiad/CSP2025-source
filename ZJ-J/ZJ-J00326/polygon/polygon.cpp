#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5, p = 998244353;
int pow_2[N];
int n, a[N], f[N], sum, ans, tot;
signed main ()
{
	
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	pow_2[0] = 1;
	for (int i = 1; i <= n; i ++) pow_2[i] = pow_2[i - 1] * 2 % p;
	
	sort (a + 1, a + n + 1);
	
	
	f[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		sum = 0;
		for (int j = a[i]; j >= 0; j --)
		{
			sum += f[j];
			sum %= p;
		}
		
		ans += pow_2[i - 1] - sum;
		ans %= p;
		
		for (int j = N - 1; j >= a[i]; j --)
		{
			f[j] += f[j - a[i]];
			f[j] %= p;
		}
//		for (int j = 0; j <= a[i] * 2; j ++)
//		{
//			cout << f[j] << " ";
//		}
//		cout << "\n" << ans << " " << a[i] << " " << sum << "\n";
		
	}
	cout << ans;
}

/*

5
1 2 3 4 5


5
2 2 3 8 10
*/
