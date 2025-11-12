#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

struct Node
{
	ll mx;
	ll d1, d2;
	ll y1, y2, y3;
}e[100010];
struct N2
{
	ll x, id;
};

N2 a[10];
ll cnt[10];

bool cmpn(N2 x, N2 y)
{
	if (x.x != y.x)
	{
		return x.x > y.x;
	}
	return x.id < y.id;
}
bool cmp(Node x, Node y)
{
	if (x.d1 != y.d1)
	{
		return x.d1 > y.d1;
	}
	else if (x.d2 != y.d2)
	{
		return x.d2 > y.d2;
	}
	else
	{
		return x.mx > y.mx;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T--)
	{
		memset(e, 0, sizeof(e));
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		ll n;
		cin >> n;
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= 3; j++)
			{
				cin >> a[j].x;
				a[j].id = j;
			}
			sort(a + 1, a + 4, cmpn);
			e[i].d1 = a[1].x - a[2].x;
			e[i].d2 = a[1].x - a[3].x;
			e[i].y1 = a[1].id;
			e[i].y2 = a[2].id;
			e[i].y3 = a[3].id;
			e[i].mx = max(a[1].x, max(a[2].x, a[3].x));
			
		}
		sort(e + 1, e + n + 1, cmp);
		long long ans = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (cnt[e[i].y1] < n / 2)
			{
				cnt[e[i].y1]++;
				ans += e[i].mx;
			}
			else if (cnt[e[i].y2] < n / 2)
			{
				cnt[e[i].y2]++;
				ans += e[i].mx - e[i].d1;
			}
			else
			{
				cnt[e[i].y3]++;
				ans += e[i].mx - e[i].d2;
			}
		}
	//	for (ll i = 1; i <= n; i++)
	//	{
	//		cout << e[i].d1 << ' ' << e[i].d2 << ' ' << e[i].mx << ' ' << e[i].y1 << ' ' << e[i].y2 << ' ' << e[i].y3 << '\n';
	//	}
	//	cout << cnt[1] << ' ' << cnt[2] << '\n';
		cout << ans << '\n';
	}
	
	return 0;
}
