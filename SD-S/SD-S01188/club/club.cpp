#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int t,n,a[N][4],cnt[5],mx[N],book[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		int ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][1] >= max(a[i][2],a[i][3])) ans += a[i][1],cnt[1]++,book[i] = 1;
			else if (a[i][2] >= max(a[i][1],a[i][3])) ans += a[i][2],cnt[2]++,book[i] = 2;
			else ans += a[i][3],cnt[3]++,book[i] = 3;
		}
		int k = max(cnt[1],max(cnt[2],cnt[3]));
		if (k <= n/2)
		{
			cout << ans << '\n';
			continue;
		}
		if (k == cnt[1])
		{
			for (int i = 1; i <= n; i++)
				if (book[i] == 1) mx[i] = a[i][1]-max(a[i][2],a[i][3]);
				else mx[i] = 999999999;
		}
		else if (k == cnt[2])
		{
			for (int i = 1; i <= n; i++)
				if (book[i] == 2) mx[i] = a[i][2]-max(a[i][1],a[i][3]);
				else mx[i] = 999999999;
		}
		else
		{
			for (int i = 1; i <= n; i++)
				if (book[i] == 3) mx[i] = a[i][3]-max(a[i][1],a[i][2]);
				else mx[i] = 999999999;
		}
		sort(mx+1,mx+n+1);
		for (int i = 1; i <= k-n/2; i++)
			ans -= mx[i];
		cout << ans << '\n';
	}
	return 0;
}
