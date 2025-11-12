#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 15;
int a[N * N], n, m, k;
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	k = a[1], sort(a + 1, a + n * m + 1, greater<int>());
	for(int i = 1, r = 1, c = 1; i <= n * m; i ++)
	{
		if(a[i] == k) { cout << c << " " << (c & 1 ? r : n - r + 1) << "\n"; break; }
		r ++;
		if(r == n + 1) r = 1, c ++;
	}
		
	return 0;
}
