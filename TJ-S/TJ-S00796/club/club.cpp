#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool A = true, B = true, C = true;
int t, n, dp[N][N], a[N][4];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1; i <= n; i++)
		{
			if(a[i][2] != 0 || a[i][3] != 0) A = false;
			if(a[i][3] != 0) B = false;
		}
		if(A)
		{
			int b[n + 1] = {}, ans = 0;
			for(int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			for(int i = n; i >= n / 2; i--) ans += b[i];
			cout << ans << '\n';
		}
		if(B)
		{
			int b[n + 1] = {}, bb[n + 1] = {}, ans = 0;
			for(int i = 1; i <= n; i++)
			{
				b[i] = a[i][1];
				bb[i] = a[i][2];
			}
			for(int i = 1; i <= n; i++)
			{
				if(b[i] >= bb[i]) ans += b[i];
				else ans += bb[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
