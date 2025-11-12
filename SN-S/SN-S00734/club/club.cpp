#include <bits/stdc++.h>
#define int long long
using namespace std;

int test,n,a[100005][3],b[3][100005],tot[3];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> test;
	while (test--)
	{
		cin >> n;
		tot[0] = tot[1] = tot[2] = 0;
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			for (int j = 0;j < 3;j++)
			{
				if (a[i][j] >= a[i][(j+1)%3] && a[i][j] >= a[i][(j+2)%3])
				{
					ans += a[i][j];
					b[j][++tot[j]] = (a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]));
					break;
				}
			}
		}
		int pos = -1;
		for (int i = 0;i < 3;i++) if (tot[i] > n/2) pos = i;
		if (pos != -1)
		{
			sort(b[pos]+1,b[pos]+tot[pos]+1);
			for (int i = 1;i <= tot[pos]-n/2;i++) ans -= b[pos][i];
		}
		cout << ans << '\n';
	}
	return 0;
}
