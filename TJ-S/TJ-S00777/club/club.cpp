#include <bits/stdc++.h>

using namespace std;

int t, n, a[100001] ,b[100001], c[100001], m[100001], p[100001];
vector<int> v;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out" ,"w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		int x = 0, y = 0, z = 0, q = 0;
		memset(m, 0, sizeof(m));
		memset(p, 0, sizeof(p));
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (max(max(a[i], b[i]), c[i]) == a[i]) 
			{
				x++;
				m[i] = 1;
				ans += a[i];
				p[i] = min(a[i] - b[i], a[i] - c[i]);
			}
			else if (max(max(a[i], b[i]), c[i]) == b[i]) 
			{
				y++;
				m[i] = 2;
				ans += b[i];
				p[i] = min(b[i] - a[i], b[i] - c[i]);
			}
			else if (max(max(a[i], b[i]), c[i]) == c[i]) 
			{
				z++;
				m[i] = 3;
				ans += c[i];
				p[i] = min(c[i] - a[i], c[i] - b[i]);
			}
		}
		if (x > n / 2) q = 1;
		else if (y > n / 2) q = 2;
		else if (z > n / 2) q = 3; 
		for (int i = 1; i <= n; i++)
		{
			if (m[i] == q) v.push_back(p[i]);
		}
		sort(v.begin(), v.end());
		int cnt = max(x - n / 2 ,max(y - n / 2, z - n / 2));
		if(v.size() > 0)for (int i = 0; i < cnt; i++) ans -= v[i];
		v.clear();
		cout << ans << endl;
	}
	return 0;
}
