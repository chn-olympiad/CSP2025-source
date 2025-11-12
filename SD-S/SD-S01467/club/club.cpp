#include <bits/stdc++.h>
using namespace std;

// 不要紧张 暴力全打满就行

typedef long long ll;
typedef pair <ll, ll> PII;
const ll N = 1e5 + 10;
const ll INF = 1e10;
const ll Mod = 1e9 + 7;

ll t, n, cnt[4], ans, tmp, g[N];

struct Node
{
	ll a, b, c;
} a[N];

bool cmp1(Node x, Node y) {return x.a > y.a;}
bool cmp2(Node x, Node y) {return x.b > y.b;}

void dfs(ll k)
{
	if (k == n + 1) 
	{
		tmp = 0;
		for (ll i = 1; i <= n; i ++) {
			ll j = g[i], p;
			if (j == 1) p = a[i].a;
			if (j == 2) p = a[i].b;
			if (j == 3) p = a[i].c;
			
			//cout << i << "选择：" << j << "，产生贡献：" << p << endl;
			tmp += p;
		}
		
		//cout << tmp << endl;
		ans = max(ans, tmp);
		return ;
	}
	
	for (ll i = 1; i <= 3; i ++)
	{
		if (cnt[i] < n / 2)
		{
			ll p;
			if (i == 1) p = a[k].a;
			if (i == 2) p = a[k].b;
			if (i == 3) p = a[k].c;
			
			cnt[i] ++;
			g[k] = i;
			dfs(k + 1);
			cnt[i] --;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	while (t --)
	{
		cin >> n;
		
		bool A = true, B = true;
		ans = 0;
		for (ll i = 1; i <= n; i ++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].b != 0 || a[i].c != 0) A = false;
			if (a[i].c != 0) B = false;
		}
		
		if (A)
		{
			sort(a + 1, a + n + 1, cmp1);
			ll ans = 0;
			for (ll i = 1; i <= n / 2; i ++) ans += a[i].a;
			cout << ans << endl;
			continue;
		}
		if (B)
		{
			sort(a + 1, a + n + 1, cmp1);
			ll ans1 = 0, ans2 = 0;
			for (ll i = 1; i <= n / 2; i ++) ans1 += a[i].a;
			for (ll i = n / 2 + 1; i <= n; i ++) ans1 += a[i].b;
			
			sort(a + 1, a + n + 1, cmp2);
			for (ll i = 1; i <= n / 2; i ++) ans2 += a[i].b;
			for (ll i = n / 2 + 1; i <= n; i ++) ans2 += a[i].a;
		
			cout << max(ans1, ans2) << endl;
			continue;
		}
		
		dfs(1);
		cout << ans << endl;
	}

	return 0;
}

// 60pts

