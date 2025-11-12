#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define int long long
int read()
{
	int res = 0, f = 1;
	char s = getchar();
	while (s < '0' || s > '9')
	{
		if (s == '-') f = -1;
		s = getchar();
	}
	while ('0' <= s && s <= '9')
	{
		res = (res << 1) + (res << 3) + (s ^ 48);
		s = getchar();
	}
	return res * f;
}
void write(int v)
{
	if (v < 10)
	{
		putchar(v + '0');
		return ;
	}
	write(v / 10);
	putchar(v % 10 + '0');
}
void wt(int v, bool f = 1)
{
	if (v < 0) putchar('-'), v = -v;
	write(v);
	putchar(f ? '\n' : ' ');
}
#define rd read()
#define pii pair<int, int>

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int Fill = 0x3f3f3f3f;
const int INF = 0x7fffffff;

int n;
int a[N][3];
int max_[N], mid[N], min_[N];
int del[N];

void solve()
{
	int i, j;
	n = rd;
	for (i = 1; i <= n; i++)
	{
		del[i] = max_[i] = mid[i] = min_[i] = -1;
		int min1 = INF, max1 = 0;
		for (j = 0; j < 3; j++)
		{
			a[i][j] = rd;
			min1 = min(min1, a[i][j]);
			max1 = max(max1, a[i][j]);
		}
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] == min1 && min_[i] == -1) min_[i] = j;
			else if (a[i][j] == max1 && max_[i] == -1) max_[i] = j;
			else mid[i] = j;
			del[i] = a[i][max_[i]] - a[i][mid[i]];
		}
//		wt(i, 0);
//		wt(max_[i], 0);
//		wt(mid[i], 0);
//		wt(min_[i]); 
	}
	priority_queue<pii, vector<pii>, greater<pii>> q[3];
	int ans[3] = {0, 0, 0};
	int maxid = -1;
	for (i = 1; i <= n; i++)
	{
		if (maxid == -1) // 还没顶到上界 
		{
			q[max_[i]].push({del[i], i});
			ans[max_[i]] += a[i][max_[i]];
			if ((int)q[max_[i]].size() == n / 2ll) // 刚刚塞满了 
			{
				maxid = max_[i];
			}
			continue;
		}
		if (max_[i] != maxid) // 不放在最大的里，不会超过上界 
		{
			ans[max_[i]] += a[i][max_[i]];
			continue;
		}
//		wt(del[i]);
		q[maxid].push({del[i], i});// 先扔进去 
		ans[maxid] += a[i][maxid];
		pii t = q[maxid].top(); // 再取出来影响最小的 
		int id = t.second, v = t.first; 
		q[maxid].pop(); // 弹掉 
		ans[maxid] -= a[id][maxid]; // 最大的减掉 
		ans[mid[id]] += a[id][mid[id]]; // 次大的加上 
//		cout << id << ' ' << a[id][maxid] << ' ' << mid[id] << ' ' << a[id][mid[id]] << endl;
	}
	wt(ans[0] + ans[1] + ans[2]);
//	wt(maxid);
}

signed main()
{
	int i, j;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = rd;
	while (T--)
	{
		solve();
	}
	return 0;
}

