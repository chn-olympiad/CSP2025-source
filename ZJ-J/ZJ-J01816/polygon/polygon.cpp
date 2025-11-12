#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int a[5555];
int n,ans = 0;
void dfs(int x,int tc,int ts,int tm)
{
	if(x == n)
	{
		if(tc >= 3 && ts > 2*tm)
		{
			ans++;
			ans %= MOD;
		}
		return;
	}
	dfs(x+1,tc,ts,tm);
	dfs(x+1,tc+1,ts+a[x+1],max(tm,a[x+1]));
}
int mc___pl(int x,int y)
{
	int res = 1;
	for(int i = 0;i < x;i++)
	{
		res *= y-i;
		res %= MOD;
	}
	return res;
}
int mc___zh(int x,int y)
{
	return mc___pl(x,y)/mc___pl(x,x);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int f = 1; cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			f = 0;
		}
	}
	if(f)
	{
		for(int i = 3;i <= n;i++)
		{
			ans += mc___zh(i,n);
			ans %= MOD;
		}
		cout << ans << "\n";
		return 0;
	}
	dfs(0,0,0,0);
	cout << ans << "\n";
	return 0;
}
