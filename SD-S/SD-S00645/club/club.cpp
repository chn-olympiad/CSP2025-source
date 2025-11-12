#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
set<pii> sa,sb,sc;
const int maxn = 1e5 + 10;
bool vis[maxn];
int a[maxn],b[maxn],c[maxn];
int n;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
	return x * f;
}
inline void write(int x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return;
}
int solve()
{
	n = read();
	int k = n / 2;
	int ans = 0;
	for(int i = 1;i <= n;i++) 
	{
		a[i] = read(),b[i] = read(),c[i] = read();
		if(a[i] >= b[i] && a[i] >= c[i]) 
		{
			sa.insert({max(b[i],c[i]) - a[i],i});
			ans += a[i];
		}
		else if(b[i] >= a[i] && b[i] >= c[i])
		{
			sb.insert({max(a[i],c[i]) - b[i],i});
			ans += b[i];
		}
		else
		{
			sc.insert({max(a[i],b[i]) - c[i],i});
			ans += c[i];
		}
	}
//	cout << sa.size() << " " << sb.size() << "\n";
	while((int)(sa.size()) > k) 
	{
		auto it = sa.rbegin();
		int x = (*it).se;
		ans -= a[x];
		ans += max(b[x],c[x]);
		sa.erase(*it);
	}
	while((int)(sb.size()) > k)
	{
		auto it = sb.rbegin();
		int x = (*it).se;
		ans -= b[x];
		ans += max(a[x],c[x]);
		sb.erase(*it);
	}
	while((int)(sc.size()) > k)
	{
		auto it = sc.rbegin();
		int x = (*it).se;
		ans -= c[x];
		ans += max(a[x],b[x]);
		sc.erase(*it);
	}
	write(ans);
	putchar('\n');
	return 0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read();
	while(t--) 
	{
		solve();
		for(int i = 1;i <= n;i++) vis[i] = 0;
		sa.clear(),sb.clear(),sc.clear();
	}
	return 0;
}
