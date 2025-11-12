//µ­³þÜ²
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10, inf = -1e16;
priority_queue < pair<int, int> > q[4][4];
int TTT = 1, ans, n, a[N][4], cnt[4], id[N];

int cal1(int a, int b, int c) 
{
	if(cnt[c] < n / 2 && !q[a][b].empty() && !q[b][c].empty()) return q[a][b].top().fi + q[b][c].top().fi;
	else return inf;
}
int cal2(int a, int b)
{
	if(cnt[b] < n / 2 && !q[a][b].empty()) return q[a][b].top().fi;
	else return inf;
}
void so1(int aa, int b, int c)
{
	int x = q[aa][b].top().se, y = q[b][c].top().se;
	cnt[aa]--, cnt[c]++, id[x] = b, id[y] = c;
	q[aa][b].pop(), q[b][c].pop();
	q[b][c].push({a[x][c] - a[x][b], x});
	q[c][b].push({a[y][b] - a[y][c], y});
}
void so2(int aa, int b, int c)
{
	int x = q[aa][b].top().se;
	cnt[aa]--, cnt[b]++, id[x] = b;
	q[aa][b].pop();
	q[b][c].push({a[x][c] - a[x][b], x});
}

void mian()
{
	cin >> n, ans = cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			while(!q[i][j].empty()) q[i][j].pop();
	for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
	for(int i = 1; i <= n; i++)
	{
		cnt[1]++, ans += a[i][1], id[i] = 1;
		q[1][2].push({a[i][2] - a[i][1], i}), q[1][3].push({a[i][3] - a[i][1], i});
	}
	
	while(true)
	{
		int v1, v2, v3, v4;
		while(!q[1][2].empty() && id[q[1][2].top().se] != 1) q[1][2].pop();
		while(!q[1][3].empty() && id[q[1][3].top().se] != 1) q[1][3].pop();
		while(!q[2][3].empty() && id[q[2][3].top().se] != 2) q[2][3].pop();
		while(!q[3][2].empty() && id[q[3][2].top().se] != 3) q[3][2].pop();
		v1 = cal1(1, 2, 3);
		v2 = cal1(1, 3, 2);
		v3 = cal2(1, 2);
		v4 = cal2(1, 3);
		
		if(cnt[1] <= n / 2 && v1 <= 0 && v2 <= 0 && v3 <= 0 && v4 <= 0) break;
		if(v1 >= v2 && v1 >= v3 && v1 >= v4) so1(1, 2, 3), ans += v1;
		else if(v2 >= v1 && v2 >= v3 && v2 >= v4) so1(1, 3, 2), ans += v2;
		else if(v3 >= v1 && v3 >= v2 && v3 >= v4) so2(1, 2, 3), ans += v3;
		else if(v4 >= v1 && v4 >= v2 && v4 >= v3) so2(1, 3, 2), ans += v4;
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
