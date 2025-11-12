#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0');ch = getchar();}
	return sum * p;
}
const int N = 1e5 + 10, INF = 1e9;
int c, r, cnt, a[N];
map<int, int> mp;
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	c = re(), r = re();
	for(int i = 1; i <= c * r; i++) a[i] = re();
	mp[a[1]] = INF;
	sort(a + 1, a + 1 + c * r);
	reverse(a + 1, a + 1 + c * r);
	
	int cnt = 0;
	for(int i = 1; i <= r; i++)
	{
		if(i & 1)
		{
			for(int j = 1; j <= c; j++)
				if(mp[a[++cnt]] == INF) return cout << i << " " << j, 0;
		}
		else
		{
			for(int j = c; j >= 1; j--)
				if(mp[a[++cnt]] == INF) return cout << i << " " << j, 0;
		}
	}
	return 0;
}
