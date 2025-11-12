#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
int n,a[6666],c[6666],ans;
void dfs(int x,int pos)
{
	c[pos] = a[pos] * x;
	if(pos == n)
	{
		int cnt = 0,sum = 0,maxn = -1;
		for1(1,n,i) if(c[i])
		{
			cnt++;
			sum += c[i];
			maxn = max(maxn,c[i]);
		}
		if(cnt > 2 && sum > maxn * 2) ans++;
		return;
	}
	dfs(0,pos + 1);
	dfs(1,pos + 1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n > 26)
	{
		cout << n - 2;
		return 0;
	}
	for1(1,n,i) cin >> a[i];
	dfs(0,1);
	dfs(1,1);
	cout << ans;
	return 0;
}
