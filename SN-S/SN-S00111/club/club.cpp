#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10;
ll T, n, a[N][10], ans;
struct edge
{
	ll x, y;
}b[N];
stack<edge> t[20];
bool cmp(edge a, edge b)
{
	return a.x < b.x;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		ans = 0;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for(ll i = 1; i <= 3; i ++)
		{
			while(t[i].size()) t[i].pop();
		}
		cin >> n;
		for(ll i = 1; i <= n; i ++)
		{
			for(ll j = 1; j <= 3; j ++)
			{
				cin >> a[i][j];
			}
			ll maxx = 0, minn = 0x3f3f3f3f, cnt1 = 0, cnt2 = 0;
			for(ll j = 1; j <= 3; j ++)
			{
				if(a[i][j] > maxx) maxx = a[i][j], cnt1 = j;
				if(a[i][j] < minn) minn = a[i][j], cnt2 = j;
			} 
			ll now = a[i][1] + a[i][2] + a[i][3] - maxx - minn;
			t[cnt1].push({maxx - now, maxx});
		}
		for(ll k = 1; k <= 3; k ++)
		{
			ll cnt = 0;
			while(t[k].size())
			{
				b[++ cnt].x = t[k].top().x;
				b[cnt].y = t[k].top().y;
				t[k].pop();
			}
			sort(b + 1, b + cnt + 1, cmp);
			ll now = cnt - n / 2;
			if(now >= 1)
			{
				for(ll i = 1; i <= now; i ++)
				{
					ans += b[i].y - b[i].x;
				}
				for(ll i = now + 1; i <= cnt; i ++) ans += b[i].y;
			}
			else
			{
				for(ll i = 1; i <= cnt; i ++) ans += b[i].y;
			}
		}
		cout << ans << endl;
	}
	return 0; 
}
