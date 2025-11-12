//just pts...
//i tried 40 minutes but i can't get anything
//i've think about dp:f[i][j]:i pre i, j the sum of next num can got. or j the cnt of choiced num(just how many S)
//don't know : how to move it.
//10:44



//T3 i used 30 min to get pre[i]
//give me 100, please.

//before this content i truly want to ak
//okey let me start to write it. 10:49.


//11:01 try n <= 500 but wa. try to 10+6/25(64pts)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;
int a[100010];
int ans = 0;
int n;
void dfs(int step, int maxn, int sum)
{
	if(step > n)
	{
		if(sum > maxn * 2)
		{
			ans++;
			ans %= MOD;
		}
		return;
	}
	dfs(step+1,max(maxn, a[step]),sum+a[step]);
	dfs(step+1,maxn,sum);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int spo1 = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i]!=1) spo1=0;
	}
	if(spo1)
	{
		int mul = 1;
		for(int i = 1; i <= n; i++) mul = (mul * 2) % MOD;
		ans = mul - n*(n-1)/2 - n - 1;
		ans = (ans % MOD + MOD) % MOD;
		cout << ans;
		return 0;
	}
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
}
