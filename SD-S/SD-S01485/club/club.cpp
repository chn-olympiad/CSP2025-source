#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50;
struct node{
	pair<int, int> m[3];
	int s1, s2;
}a[N];
int n, ans;
int cnt[3];
bool cmp(node x, node y)
{
	return x.s1 == y.s1 ? x.s1 > y.s1 : x.s2 > y.s2;
}
bool cmp1(pair<int, int> x, pair<int, int> y)
{
	return x.first > y.first;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for(int i = 1; i <= n; ++i)
		{
			int x, y, z;
			cin >> a[i].m[0].first >> a[i].m[1].first >> a[i].m[2].first;
			a[i].m[0].second = 0, a[i].m[1].second = 1, a[i].m[2].second = 2;
			sort(a[i].m, a[i].m + 3, cmp1);
			a[i].s1 = a[i].m[0].first - a[i].m[2].first;
			a[i].s2 = a[i].m[0].first - a[i].m[1].first;		
		}
		int max = n / 2;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; ++i)
		{
			node t = a[i];
			for(int j = 0; j <= 2; ++j)
			{
				if(cnt[t.m[j].second] >= max) continue;
				cnt[t.m[j].second]++;
				ans += t.m[j].first;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

