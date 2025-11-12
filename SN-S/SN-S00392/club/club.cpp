// club

#include <bits/stdc++.h>

#define int long long
#define pii pair <int, int>

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

inline int read()
{
	int val = 0;
	bool si = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) si ^= ch == '-';
	for (;  isdigit(ch); ch = getchar())
		val = (val << 3) + (val << 1) + (ch ^ 48);
	return si == 0 ? val : -val;
}

const int N = 1e5 + 5;

int T, n;
int b[N][3];
pii a[N][3];

priority_queue <pii, vector <pii>, greater <pii> > hep[3];

inline void init()
{
	for (int i = 0; i <= 2; i ++)
		while (0 == hep[i].empty())
			hep[i].pop();
	
	n = read();
	for (int i = 1; i <= n; i ++)
	{
		a[i][0] = make_pair(read(), 0);
		a[i][1] = make_pair(read(), 1);
		a[i][2] = make_pair(read(), 2);
		sort(a[i], a[i] + 3, greater <pii> ());
		b[i][a[i][0].second] = 0;
		b[i][a[i][1].second] = 1;
		b[i][a[i][2].second] = 2;
//		clog << a[i][0].second << " " << a[i][1].second << " " << a[i][2].second << endl;
	}
}

inline void work()
{
	for (int i = 1; i <= n; i ++)
	{
		hep[a[i][0].second].push(make_pair(a[i][0].first - a[i][1].first, i));
		if (hep[a[i][0].second].size() > n / 2)
		{
			int u = hep[a[i][0].second].top().second;
			hep[a[i][0].second].pop();
			hep[a[u][1].second].push(make_pair(INF, u));
		}
	}
	int ans = 0;
	for (int i = 0; i <= 2; i ++)
		while (0 == hep[i].empty())
		{
			int u = hep[i].top().second;
			hep[i].pop();
			ans += a[u][b[u][i]].first;
		}
	printf("%lld\n", ans);
}

signed main()
{
	freopen("club.in" , "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = read();
	while (T --)
	{
		init();
		work();
//		clog << endl;
	}	
	
	return 0;
}
