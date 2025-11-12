#include <bits/stdc++.h>
using namespace std;
const int CN = 1e5+5;
int t,n,a,b,c,mxn,cnt[4],sum[CN][4],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a >> b >> c;
			if (a >= b && a >= c)
				sum[1][++cnt[1]] = a-max(b,c);
			else if (b >= a && b >= c)
				sum[2][++cnt[2]] = b-max(a,c);
			else
				sum[3][++cnt[3]] = c-max(a,b);
			ans += max(max(a,b),c);
		}
		if (cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2)
		{
			cout << ans << '\n';
			continue;
		}
		for (int i = 1;i <= 3;i++)
			if (cnt[i] > n/2)
			{
				mxn = i;
				continue;
			}
		sort(sum[mxn]+1,sum[mxn]+cnt[mxn]+1);
		for (int i = 1;cnt[mxn] > n/2;i++)
		{
			ans -= sum[mxn][i];
			cnt[mxn]--;
		}
		cout << ans << '\n';
	}
	return 0;
}
