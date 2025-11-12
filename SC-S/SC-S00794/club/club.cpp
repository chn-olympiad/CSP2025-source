#include <bits/stdc++.h>
using namespace std;

int a[200010][3], m0[200010], m1[200010], m2[200010], s[200010];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int cnt0, cnt1, cnt2;
		cnt0 = cnt1 = cnt2 = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int t = a[i][0], id = 0;
			if (a[i][1] > t)
			{
				t = a[i][1];
				id = 1;
			}
			if (a[i][2] > t)
			{
				t = a[i][2];
				id = 2;
			}
			ans += t;
			if (id == 0) m0[++cnt0] = i;
			else if (id == 1) m1[++cnt1] = i;
			else m2[++cnt2] = i;
		}
		int cnt = 0;
		if (cnt0 > (n >> 1))
		{
			for (int i = 1; i <= cnt0; i++)
				s[++cnt] = a[m0[i]][0] - max(a[m0[i]][1], a[m0[i]][2]);
			sort(s+1, s+cnt+1);
			for (int i = 1; i <= cnt0 - (n >> 1); i++)
				ans -= s[i];
		}
		if (cnt1 > (n >> 1))
		{
			for (int i = 1; i <= cnt1; i++)
				s[++cnt] = a[m1[i]][1] - max(a[m1[i]][0], a[m1[i]][2]);
			sort(s+1, s+cnt+1);
			for (int i = 1; i <= cnt1 - (n >> 1); i++)
				ans -= s[i];
		}
		if (cnt2 > (n >> 1))
		{
			for (int i = 1; i <= cnt2; i++)
				s[++cnt] = a[m2[i]][2] - max(a[m2[i]][0], a[m2[i]][1]);
			sort(s+1, s+cnt+1);
			for (int i = 1; i <= cnt2 - (n >> 1); i++)
				ans -= s[i];
		}
		cout << ans << endl;
	}
	return 0;
}