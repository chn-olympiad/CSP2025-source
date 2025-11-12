#include<bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 5e5 + 10;
int n, tot, cnt[4], ans, vis[N], t[N];
struct info
{
	int x, y, z;
}a[N];
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = re();
	while(T--)
	{
		n = re(), ans = 0, tot = 0, cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1; i <= n; i++) 
		{
			a[i].x = re(), a[i].y = re(), a[i].z = re();
			int maxn = max({a[i].x, a[i].y, a[i].z});
			if(maxn == a[i].x) cnt[1]++, vis[i] = 1;
			else if(maxn == a[i].y) cnt[2]++, vis[i] = 2;
			else cnt[3]++, vis[i] = 3;
			ans += maxn;
		}

		if(cnt[1] > n / 2)
		{
			for(int i = 1; i <= n; i++)
				if(vis[i] == 1) t[++tot] = max(a[i].y - a[i].x, a[i].z - a[i].x);
			sort(t + 1, t + 1 + tot);
			for(int i = tot; cnt[1] > n / 2; i--) cnt[1]--, ans += t[i];
		}
		else if(cnt[2] > n / 2)
		{
			for(int i = 1; i <= n; i++)
				if(vis[i] == 2) t[++tot] = max(a[i].x - a[i].y, a[i].z - a[i].y);
			sort(t + 1, t + 1 + tot);
			for(int i = tot; cnt[2] > n / 2; i--) cnt[2]--, ans += t[i];
		}
		else if(cnt[3] > n / 2)
		{
			for(int i = 1; i <= n; i++)
				if(vis[i] == 3) t[++tot] = max(a[i].x - a[i].z, a[i].y - a[i].z);
			sort(t + 1, t + 1 + tot);
			for(int i = tot; cnt[3] > n / 2; i--) cnt[3]--, ans += t[i];
		}
		cout << ans << "\n";
	}
	return 0;
}