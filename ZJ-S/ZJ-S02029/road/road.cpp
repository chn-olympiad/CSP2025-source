#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e4 + 10, M = 2e6 + 10;
int n, m, k, g[N], a1[20][N];
int h[N], e[M], ne[M], idx;
void read(int &s)
{
	s = 0; int f = 1; char c = getchar();
	for(; c < 48 || c > 57; c = getchar()) (c == '-') && (f == -1);
	for(; c >= 48 && c <= 57; c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	s *= f;
	return;
}
void add(int a, int b, int c){e[++ idx] = b, ne[idx] = h[a], h[a] = idx;}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i ++)
	{
		int a, b, c;
		read(a), read(b), read(c);
		add(a, b, c), add(b, a, c);
	}
	for(int j = 1; j <= k; j ++)
	{
		read(g[i]);
		for(int i = 1; i <= n; i ++) read(a1[j][i]);
	}
	
	return 0;
}
