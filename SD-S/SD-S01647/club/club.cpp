#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
inline int read() 
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
int T, n, cnt[4], ans, p, ct;
int a[100003][4], N, b[100003];
vector<int> g[4];
inline bool cmp(int A, int B)
{
	return b[A] < b[B];
}
inline void solve()
{
	n = read(), N = n >> 1;
	cnt[1] = cnt[2] = cnt[3] = ans = 0;
	g[1].clear(), g[2].clear(), g[3].clear();
	for(int i = 1;i <= n;++ i)
	{
		ct = b[i] = 0;
		for(int j = 1;j <= 3;++ j)
		{
			a[i][j] = read();
			if(a[i][j] > ct)
			{
				b[i] = a[i][j] - ct;
				ct = a[i][j];
				p = j;
			}
			else b[i] = min(b[i], ct - a[i][j]);
		}
		++ cnt[p], ans += ct, g[p].push_back(i);
	}
	ct = max(max(cnt[1], cnt[2]), cnt[3]);
	if(ct <= N) return (void)(cout << ans << '\n');
	if(cnt[1] == ct) p = 1;
	else if(cnt[2] == ct) p = 2;
	else p = 3;
	sort(g[p].begin(), g[p].end(), cmp);
	for(int i : g[p])
	{
		-- ct;
		ans -= b[i];
		if(ct == N) break;
	}
	cout << ans << '\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T --) solve();
	return 0;
}
