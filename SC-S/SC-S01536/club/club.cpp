//club
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)\

#define x first
#define y second

const int N = 1e5 + 5;
int n, f[N], res;
struct P 
{
	pair<int, int> best, second;
	int delta;
} p[N];

int cnt[3];
queue<int> q[3];

void insert(int i)
{
	pair<int, int> &a = p[i].best, &b = p[i].second;
	
	if (cnt[a.y] * 2 == n)
	{
		int id = q[a.y].front();
		pair<int, int> &c = p[id].best, &d = p[id].second;
		q[a.y].pop();
		
		int delta = d.x - c.x + a.x - b.x;
		if (delta >= 0) 
		{
			q[a.y].push(i);
			q[d.y].push(id);
			cnt[d.y] ++;
		}
		else 
		{
			q[c.y].push(id);
			q[b.y].push(i);
			cnt[b.y] ++;
		}
	}
	else 
	{
		cnt[a.y] ++;
		q[a.y].push(i);
	}
}

void calc(queue<int> &q, int id)
{
	while (q.size())
	{
		res += p[q.front()].best.y == id ? p[q.front()].best.x : p[q.front()].second.x;
		q.pop();
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	file(club);
	int T;
	cin >> T;
	while (T --)
	{
		res = 0, cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for (int i = 1; i <= n; ++ i)
		{
			pair<int, int> a[3];
			for (int j = 0; j < 3; ++ j) cin >> a[j].first, a[j].second = j;
			sort(a, a + 3);
			
			p[i].best = a[2], p[i].second = a[1];
			p[i].delta = a[2].x - a[1].x;
		}
		
		sort(p + 1, p + 1 + n, [](P a, P b){
			return a.delta > b.delta;
		});
		
		for (int i = 1; i <= n; ++ i) 
		{
			insert(i);
		}
		for (int i = 0; i < 3; ++ i) calc(q[i], i);
		
		cout << res << '\n';
	}
	return 0;
}