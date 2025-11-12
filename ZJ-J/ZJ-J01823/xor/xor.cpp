#include <bits/stdc++.h>
using namespace std;

int n, k;

int f[1005][1005];

struct Node
{
	int l, r;
	
	bool operator < (Node x) const {
		if (l != x.l)
			return l > x.l;
		return (r - l) > (x.r - x.l); 
	}	
};

Node a[1005], b[1005];
int dif[1005];
int l = 0, l1 = 0, mx = 0;

void dfs(int x)
{
	if (x > l && l1 <= l)
	{
		memset(dif, 0, sizeof dif);
		for (int i = 1; i <= l1; i++)
			dif[b[i].l]++, dif[b[i].r + 1]--;
			
		for (int i = 1; i <= n; i++)
			dif[i] = dif[i] + dif[i - 1];
		
		bool f = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dif[i] > 1)
			{
				f = 1;
				break;
			}
		}
		
		if (!f)
			mx = max(mx, l1);
			
		return;
	}
	
	dfs(x + 1);
	
	l1++;
	b[l1] = a[x];
	dfs(x + 1);
	l1--;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> f[i][i];
		
	priority_queue<Node> qu;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			f[i][j] = f[i][j - 1] ^ f[j][j];
			if (f[i][j] == k)
				qu.push({i, j});
		}
			
	while (!qu.empty())
	{
		l++;
		a[l] = qu.top();
		qu.pop();
	}
	
	dfs(1);
	
	cout << mx;
	
	return 0;
}