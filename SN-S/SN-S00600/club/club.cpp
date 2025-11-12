#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int read ()
{
	int x = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9')
		w = (ch == '-' ? -1 : w), ch = getchar ();
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar (); 
	return x * w;
}

const int N = 1e5 + 7;

int n, res, a[N][4];

priority_queue <pair <int, int> , vector <pair <int, int> > , greater <pair <int, int> > > pq[3]; 

signed main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T = read ();
	while (T --)
	{
		n = read ();
		for (int i = 1; i <= n; ++ i)
		{
			a[i][1] = read (), a[i][2] = read (), a[i][3] = read ();
			int id = 1, id2 = 1;
			if (a[i][2] > a[i][id])
				id = 2;
			if (a[i][3] > a[i][id])
				id = 3;
			if (id == id2)
			{
				if (a[i][2] > a[i][3])
					id2 = 2;
				else
					id2 = 3;
			}
			else
			{
				if (a[i][1] > a[i][5 - id])
					id2 = 1;
				else
					id2 = 5 - id;
			}
			if (pq[id].size () == n / 2)
			{
				pair <int, int> x = pq[id].top ();
				if (x.first > a[i][id] - a[i][id2])
					res += a[i][id2];
				else
				{
					pq[id].pop ();
					res += a[i][id];
					res -= x.first;
					pq[id].push ({a[i][id] - a[i][id2], id2});
				}
			}
			else
			{
				res += a[i][id];
				pq[id].push ({a[i][id] - a[i][id2], id2});
			}
		}
		cout << res << '\n';
		res = 0;
		while (pq[1].size ())
			pq[1].pop ();
		while (pq[2].size ())
			pq[2].pop ();
		while (pq[3].size ())
			pq[3].pop ();
	}
	return 0;
}
