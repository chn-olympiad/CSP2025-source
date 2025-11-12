#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e6 + 10;
int q, n;
string a[N], b[N];
string x, y, s;
int l, r;
int kmp[N];
int ans;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1;i <= n; i ++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1;i <= q; i ++)
	{
		cin >> x >> y;
		l = 0;
		r = x.size() -  1;
		while(x[l] == y[l])	l ++;
		while(x[r] == y[r])	r --;
		for (int j = l;j <= r; j ++)
		{
			s += x[j];
		}
		for (int j = 1;j <= n; j ++)
		{
			if(s.find (a[j]) != -1 || s.find (b[j]) != -1 || a[j].find(s) != -1 || b[j].find(s) != -1)
			{
				
			}
			else continue;
			ans += (s.find (a[j]) != -1) + (s.find (b[j]) != -1) + (a[j].find(s) != -1) + (b[j].find(s) != -1);
		}
		cout << ans << ' ';
	}
	return 0;
}
