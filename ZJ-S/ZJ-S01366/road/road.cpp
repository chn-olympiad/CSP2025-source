#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int read()
{
	int x = 0,f = 1;
	char c = getchar();
	while (c < 48 || c > 57)
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= 48 && c <= 57) x = x * 10 + c - 48,c = getchar();
	return x * f; 
}

void write(int x)
{
	if (x < 0) putchar('-'),x = -x;
	if (x / 10) write(x / 10);
	putchar(x % 10 + 48);
	return;
}

struct node
{
	int x,y,z;
}a[1200010];

int n,m,k,t,x,y,c[15],f[1100][10100],s[1100];

bool cmp(node x,node y) {return x.z < y.z;}

int find(int rt,int x) {return f[rt][x] == x ? x : f[rt][x] = find(rt,f[rt][x]);}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for (int i = 1;i <= m;i++) a[i].x = read() - 1,a[i].y = read() - 1,a[i].z = read();
	t = m;
	for (int i = 0;i < k;i++)
	{
		c[i] = read();
		for (int j = 0;j < n;j++) a[++t] = {n + i,j,read()};
	}
	sort(a + 1,a + t + 1,cmp);
	for (int i = 0;i < (1 << k);i++) for (int j = 0;j < n + k;j++) f[i][j] = j;
	for (int i = 1;i <= t;i++)
	{
		x = find(0,a[i].x),y = find(0,a[i].y);
		if (x == y) continue;
		if (x < n) f[0][x] = y,s[0] += a[i].z;
		for (int j = 1;j < (1 << k);j++)
			if (a[i].x < n || (j >> (a[i].x - n) & 1))
			{
				x = find(j,a[i].x),y = find(j,a[i].y);
				if (x != y) f[j][x] = y,s[j] += a[i].z;
			}
	}
	for (int i = 1;i < (1 << k);i++)
	{
		for (int j = 0;j < k;j++) if (i >> j & 1) s[i] += c[j];
		s[0] = min(s[0],s[i]);
	}
	write(s[0]);
	return 0;
}
