#include <bits/stdc++.h>
using namespace std;
int T, n, a1[200005], a2[200005], a3[200005], maxn = 0;
void dfs(int num, int ans, int cnt1, int cnt2, int cnt3, int con)
{
	if(num == n - 1 && ans > maxn)
	{
		maxn = ans;
		return;
	}
	//cout << num << " " << ans << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
	if(cnt1 < n / 2)
	{
		dfs(num + 1, ans + a1[num + 1], cnt1 + 1, cnt2, cnt3, con);
	}
	if(cnt2 < n / 2)
	{
		dfs(num + 1, ans + a2[num + 1], cnt1, cnt2 + 1, cnt3, con);
	}
	if(con != 3 && cnt3 < n / 2)
	{
		dfs(num + 1, ans + a3[num + 1], cnt1, cnt2, cnt3 + 1, con);
	}
	return;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cin >> n;
		bool chk = true;
		for(int i = 0; i < n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
			if(a3[i] != 0)
			{
				chk = false;
			}
		}
		if(chk)
		{
			dfs(-1, 0, 0, 0, 0, 3);	
		}
		else
		{
			dfs(-1, 0, 0, 0, 0, 0);	
		}
		cout << maxn << endl;
		maxn = 0;
	}
	return 0;
}
