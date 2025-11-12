#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node
{
	int d[3];
	int no[3];
	int mx, mn, md;
	node()
	{
		d[0] = d[1] = d[2] = 0;
		no[0] = no[1] = no[2] = 0;
		mn = mx = md = 0;
	}
	void init()
	{
		int Mx = max({no[0], no[1], no[2]});
		int Mn = min({no[0], no[1], no[2]});
		bool f[3] = {0, 0, 0};
		for (int i = 0; i < 4; i++)
			if (no[i] == Mx)
				mn = i, f[i] = 1;
		for (int i = 0; i < 4; i++)
			if (no[i] == Mn)
				mx = i, f[i] = 1;
		for (int i = 0; i < 4; i++)
			if (!f[i])
				md = i;
	}
	get()
	{
		no[0] = max(d[1], d[2]) - d[0];
		no[1] = max(d[0], d[2]) - d[1];
		no[2] = max(d[0], d[1]) - d[2];
	}
	bool operator < (node x) 
	{
		int _mn = min({no[0], no[1], no[2]}), _mnx = min({x.no[0], x.no[1], x.no[2]});
		int _md = d[md], _mdx = d[x.md];
		int _mx = d[mx], _mxx = d[x.mx];
		return _mn == _mx ? (_md == _mdx ? (_mx == _mxx ? (rand() & 1) : _mx > _mxx) : _md > _mdx) : _mn < _mnx;
	}
	void tozero()
	{
		d[0] = d[1] = d[2] = 0;
		no[0] = no[1] = no[2] = 0;
		mn = mx = md = 0;
	}
} a[N];
int n;

void solve()
{
	scanf("%d", &n);
//	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i].tozero();
		scanf("%d %d %d", &a[i].d[0], &a[i].d[1], &a[i].d[2]);
//		cin >> a[i].d[0] >> a[i].d[1] >> a[i].d[2];
		a[i].get();
		a[i].init();
	}
	sort(a + 1, a + n + 1);
	int ct[3] = {0, 0, 0};
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ct[a[i].mx] < n / 2)
		{
			ct[a[i].mx]++;
			ans += a[i].d[a[i].mx];
		}
		else if (ct[a[i].md] < n / 2)
		{
			ct[a[i].md]++;
			ans += a[i].d[a[i].md];
		}
		else if (ct[a[i].mn] < n / 2)
		{
			ct[a[i].mn]++;
			ans += a[i].d[a[i].mn];
		}
	}
//	cout << ans << '\n';
	printf("%lld\n", ans);
} 
int main()
{
	srand(time(0));
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int Q;
//	cin >>  Q;
	scanf("%d", &Q);
	while (Q--)
		solve();
	return 0;
}