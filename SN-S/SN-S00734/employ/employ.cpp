#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[200005],b[200005];
string s;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = '-'+s;
	for (int i = 1;i <= n;i++) cin >> a[i],b[i] = i;
	int ans = 0;
	do
	{
		int q = 0,z = 0;
		for (int i = 1;i <= n;i++)
		{
			if (q >= a[b[i]])
			{
				q++;
				continue;
			}
			if (s[i] == '1') z++;
			else q++;
		}
		if (z >= m) ans++;
	}
	while (next_permutation(b+1,b+n+1));
	cout << ans;
	return 0;
}
