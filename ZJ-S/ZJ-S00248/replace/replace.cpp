#include	<algorithm>
#include	<iostream>
#define		int		long long
using namespace std;
using pii = pair<int,int>;
using pss = pair<string,string>;
constexpr int maxn = 2e5+4;
constexpr int maxl = 5e6+4;
constexpr int P = 1331;

int n, q;
pss s[maxn];
pii hsh[maxn];
int pwd[maxl];
unsigned int h[maxl];

void init (string s)
{
	h[0] = s[0];
	pwd[0] = 1;
	for (int i = 1; i < s.length(); i++)
	{
		pwd[i] = pwd[i - 1] * P;
		h[i] = h[i - 1] * P + s[i];
	}
}

inline int rmq (int l, int r)
{
	if (!l)
		return h[r];
	else if (l > r)
		return 0;
	else
		return h[r] - h[l - 1] * pwd[r - l + 1];
}

inline int gethash (string s)
{
	unsigned int ans = 0;
	for (auto i : s)
		ans = ans * P + i;
	return ans;
}

signed main (void)
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;
	sort (s + 1, s + n + 1, [&] (const pss &x, const pss &y) { return x.first.length() < y.first.length(); });
	if (n <= 100)
	{
		while (q--)
		{
			string u, v;
			cin >> u >> v;
			if (u.length() != v.length())
			{
				puts ("0");
				continue;
			}
			int lst = 0;	// lst is the last index where u[lst] = v[lst]
			while (lst + 1 < u.length() && u[lst + 1] == v[lst + 1])
				lst++;
			int ans = 0;
			for (int i = 0; i <= lst + 1 && i < u.length(); i++)
			{
				for (int j = 1; j <= n && i + s[j].first.length() - 1 < u.length(); j++)
				{
					// cout << i << ' ' << j << endl;
					int len = s[j].first.length();
					if (u.substr(i, len) == s[j].first && u.substr(0, i) + s[j].second + u.substr(i + len) == v)
						ans++;
				}
				// cout << i << ' ' << ans << endl;
			}
			cout << ans << endl;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			hsh[i].first = gethash (s[i].first);
			hsh[i].second = gethash (s[i].second);
		}
		while (q--)
		{
			string u, v;
			cin >> u >> v;
			if (u.length() != v.length())
			{
				puts ("0");
				continue;
			}
			init (u);
			int hv = gethash (v);
			int lst = 0;	// lst is the last index where u[lst] = v[lst]
			while (lst + 1 < u.length() && u[lst + 1] == v[lst + 1])
				lst++;
			int ans = 0;
			for (int i = 0; i <= lst + 1 && i < u.length(); i++)
			{
				for (int j = 1; j <= n && i + s[j].first.length() - 1 < u.length(); j++)
				{
					int len = s[j].first.length();
					if (rmq (i, i + len - 1) == hsh[j].first)
					{
						if (h[i] * pwd[u.length() - i] + hsh[j].second * pwd[u.length() - i - len] + rmq (i + len, u.length() - 1) == hv)
							ans++;
					}
				}
				// cout << i << ' ' << ans << endl;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
