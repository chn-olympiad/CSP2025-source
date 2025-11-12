// xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000000
#define infll 1000000000000000000ll
using namespace std;
int aqx, n, m;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	int a;
	cin >> n >> m >> a;
	int k = 1, t = n * m - 1;
	while (t--)
	{
		int x; cin >> x;
		if (x > a) k++;
	}
	int ansx = k % (n * 2), ansy = k / (n * 2) * 2 + 1;
	if (!ansx) {ansx = n * 2; ansy -= 2;}
	if (ansx > n) {ansx = n * 2 + 1 - ansx; ansy++;}
	cout << ansy << " " << ansx << "\n";
	return;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
