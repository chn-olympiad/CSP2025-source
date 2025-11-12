#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int t;
int n, ans;
struct nod{
	int x, y, z;
} a[100010];

void dfs(int id, int s,int t1,int t2,int t3)
{
	if (t1 > (n>>1) || t2 > (n>>1) || t3 > (n>>1)) return;
	if (id == n+1)
	{
		ans = max(ans, s);
		return;
	}
	dfs(id+1, s+a[id].x, t1+1,t2,t3);
	dfs(id+1, s+a[id].y, t1,t2+1,t3);
	dfs(id+1, s+a[id].z, t1,t2,t3+1);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
