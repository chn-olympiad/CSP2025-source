#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][3];
int ans = 0;
vector<int> b[3];
int n;
struct Node
{
	int a, b, c;
}a1[N];
struct Nod2
{
	int sum, i;
	bool operator < (const Nod2 &w) const
	{
		return sum < w.sum;
	}
	bool operator > (const Nod2 &w) const
	{
		return sum > w.sum;
	}
}c[3];
queue<Node> q;
priority_queue<Nod2, vector<Nod2>, greater<Nod2> > q2[3];
void dfs(int n2, int cnt)
{
	if (n2 > n) 
	{
		ans = max(ans, cnt);
		return;
	}
	int len1, len2, len3;
	len1 = b[0].size(), len2 = b[1].size(), len3 = b[2].size();
	if (len1 < (n >> 1))
	{
		b[0].push_back(n2);
		dfs(n2 + 1, cnt + a[n2][0]);
		b[0].pop_back();
	}
	if (len2 < (n >> 1))
	{
		b[1].push_back(n2);
		dfs(n2 + 1, cnt + a[n2][1]);
		b[1].pop_back();
	}
	if (len3 < (n >> 1))
	{
		b[2].push_back(n2);
		dfs(n2 + 1, cnt + a[n2][2]);
		b[2].pop_back();
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t --)
	{
		memset(a, 0, sizeof a);
		ans = 0;
		for (int i = 0; i < 3; i ++)
			while(!b[i].empty()) b[i].pop_back();
		while (!q.empty()) q.pop();
		for (int i = 0; i < 3; i ++)
			while (!q2[i].empty()) q2[i].pop();
		cin >> n;
		if (n < 30)
		{
			for (int i = 1; i <= n; i ++)
				cin >> a[i][0] >> a[i][1] >> a[i][2];
			dfs(1, 0);
			cout << ans << "\n";
		}
		else
		{
			for (int i = 1; i <= n; i ++)
			{
				cin >> a1[i].a >> a1[i].b >> a1[i].c;
				q.push(a1[i]);
			}
			while (!q.empty())
			{
				Node b = q.front();
				q.pop();
				int a2 = b.a, b2 = b.b, c1 = b.c;
				
				c[0].sum = a2, c[1].sum = b2, c[2].sum = c1;
				for (int i = 0; i < 3; i ++) c[i].i = i;
				sort(c, c + 3);
				for (int i = 2; i >= 0; i --)
				{
					int j = c[i].i;
					if (q2[j].size() + 1 <= (n >> 1))
					{
						q2[j].push(c[i]);
						break;
					}
					if (c[i] > q2[j].top())
					{
	//					cout << "===========================\n";
						Nod2 e = q2[j].top();
						q.push(a1[e.i]);
						q2[j].pop();
						q2[j].push(c[i]);
						break;
					}	
				}
			}
			int ans = 0;
			for (int i = 0; i < 3; i ++)
			{
				while(!q2[i].empty())
				{
					Nod2 e = q2[i].top();
					ans += e.sum;
					q2[i].pop();
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
