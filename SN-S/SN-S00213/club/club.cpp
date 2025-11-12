//n是偶数这个性质使得贪心一定是正确的
#include<bits/stdc++.h>

using namespace std;

#define N 100005
#define int long long

int n, a[N][4], ans;
struct person{int delta, id;};
bool cmp(person x, person y){return x.delta < y.delta;}
vector<person> b[4];

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n; ans = 0;
		b[1].clear(), b[2].clear(), b[3].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] == max({a[i][1], a[i][2], a[i][3]}))
				b[1].push_back({min(a[i][1] - a[i][2], a[i][1] - a[i][3]), i});
			else if(a[i][2] == max({a[i][1], a[i][2], a[i][3]}))
				b[2].push_back({min(a[i][2] - a[i][1], a[i][2] - a[i][3]), i});
			else 
				b[3].push_back({min(a[i][3] - a[i][1], a[i][3] - a[i][2]), i});
			ans += max({a[i][1], a[i][2], a[i][3]});
		}
		int lim = n / 2;
		if(b[1].size() <= lim && b[2].size() <= lim && b[3].size() <= lim)
		{
			cout << ans << "\n";
			continue;
		}
		
		for(int i = 1; i <= 3; i++)sort(b[i].begin(), b[i].end(), cmp);
		
		if(b[1].size() > lim)
		{
			int x = b[1].size() - lim;
			for(int i = 0; i < x; i++)ans -= b[1][i].delta;
			cout << ans << "\n";
			continue;
		}
		if(b[2].size() > lim)
		{
			int x = b[2].size() - lim;
			for(int i = 0; i < x; i++)ans -= b[2][i].delta;
			cout << ans << "\n";
			continue;
		}
		if(b[3].size() > lim)
		{
			int x = b[3].size() - lim;
			for(int i = 0; i < x; i++)ans -= b[3][i].delta;
			cout << ans << "\n";
			continue;
		}
	}
	return 0;
} 
