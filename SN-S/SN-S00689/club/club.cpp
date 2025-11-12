#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;
int n, ccnt[4], a[N][4], c[N], num[N];

int main()
{
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	
	for (int id_testdata = 0; id_testdata < T; ++ id_testdata)
	{
		ccnt[1] = ccnt[2] = ccnt[3] = 0;
		
		cin >> n;
		
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			
			if (a[i][2] <= a[i][1] && a[i][3] <= a[i][1])
			{
				num[i] = 1;
			}
			else if (a[i][1] <= a[i][2] && a[i][3] <= a[i][2])
			{
				num[i] = 2;
			}
			else
			{
				num[i] = 3;
			}
			
			ans += a[i][num[i]], ++ ccnt[num[i]];
		}
		
		if (ccnt[1] <= (n >> 1) && ccnt[2] <= (n >> 1) && ccnt[3] <= (n >> 1))
		{
			cout << ans << '\n';
			continue;
		}
		
		int cid = -1;
		if ((n >> 1) < ccnt[1])
		{
			cid = 1;
		}
		else if ((n >> 1) < ccnt[2])
		{
			cid = 2;
		}
		else
		{
			cid = 3;
		}
		
		for (int i = 1; i <= n; ++ i)
		{
			if (num[i] != cid)
			{
				c[i] = -0x3f3f3f3f;
				continue;
			}
			
			int amax = 0;
			for (int j = 1; j <= 3; ++ j)
			{
				if (j != cid)
				{
					amax = max(amax, a[i][j]);
				}
			}
			c[i] = amax - a[i][cid];
		}
		
		sort(c + 1, c + n + 1, greater<int>());
		
		int rcnt = ccnt[cid] - (n >> 1);
		for (int i = 1; i <= rcnt; ++ i)
		{
			ans += c[i];
		}
		
		cout << ans << '\n';
	}
	return 0;
}
