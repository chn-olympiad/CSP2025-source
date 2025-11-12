#include <bits/stdc++.h>
using namespace std;
long long n, t, a[100005][4], mx[4], c[100005], ans, b[100005];
vector<int> v;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		v.clear();
		ans = mx[1] = mx[2] = mx[3] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int mx1 = max({a[i][1], a[i][2], a[i][3]}), mx3 = min({a[i][1], a[i][2], a[i][3]});
			int mx2 = mx1^mx3^a[i][1]^a[i][2]^a[i][3];
			c[i] = mx1 - mx2;
			ans += mx1;
			if(mx1 == a[i][1]) b[i] = 1, mx[1]++;
			else if(mx1 == a[i][2]) b[i] = 2, mx[2]++;
			else if(mx1 == a[i][3]) b[i] = 3, mx[3]++; 
			else assert(0);
		}
		int mxcnt = max({mx[1], mx[2], mx[3]});
		if(mxcnt < n/2)
		{
			cout << ans << '\n';
			continue;
		}
		int ovid;
		if(mx[1] > n/2) ovid = 1;
		if(mx[2] > n/2) ovid = 2;
		if(mx[3] > n/2) ovid = 3;
		for(int i = 1; i <= n; i++)
		{
			if(b[i] == ovid) v.push_back(c[i]);
		}
		sort(v.begin(), v.end());
		for(int i = mxcnt, j = 0; i > n/2; i--, j++)
		{
			ans -= v[j];
		}
		cout << ans << '\n';
	}
	return 0;
}

