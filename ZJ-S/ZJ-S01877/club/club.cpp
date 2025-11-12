#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n;

struct Node
{
	int num, x, d, s;
	
	bool operator < (Node x) const
	{
		if (s != x.s)
			return x.s > s;
		return x.num > num;
	}
};

int vis[N];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		priority_queue<Node> pq;
		
		for (int i = 1; i <= n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			
			pq.push({a, i, 1, min(a - b, a - c)});
			pq.push({b, i, 2, min(b - a, b - c)});
			pq.push({c, i, 3, min(c - b, c - a)});
			
			vis[i] = 0;
		}
		
		int cnt[4];
		int ans = 0;
		
		cnt[1] = cnt[2] = cnt[3] = 0;
		
		while (!pq.empty())
		{
			Node now = pq.top();
			pq.pop();
			
			if (vis[now.x] || cnt[now.d] == n / 2)
				continue;
			
			ans += now.num;
			vis[now.x] = 1;
			cnt[now.d]++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}