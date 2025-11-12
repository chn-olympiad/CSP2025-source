#include <iostream>
#include <cstdio>
#include <queue>
#define MAXN 500001
using namespace std;
struct node {int l, r, cnt;};
int n, k, a[MAXN], S[MAXN], prev, cnt, ans;
void bfs()
{
	queue<node> q;
	q.push((node){0, 0, 0});
	while (!q.empty())
	{
		node u = q.front();
		q.pop();
		for (int i = u.r + 1; i <= n; i++)
		{
			if (i <= u.r && i >= u.l)
				continue;
			for (int j = i; j <= n; j++)
			{
				if (j <= u.r && j >= u.l)
					continue;
				if ((S[j] ^ S[i - 1]) == k)
					q.push((node){i, j, u.cnt + 1});
			}
		}
		// cerr << u.cnt << " Hello" << endl;
		ans = max(ans, u.cnt);
	}
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		S[i] = S[i - 1] ^ a[i];
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}