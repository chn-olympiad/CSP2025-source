#include <iostream>
#include <cstdio>
using namespace std;
const int Mod = 998244353;
long long n,ans,a[5005];
bool vis[5005];
long long apl(int n,int m)
{
	long long res = 1;
	for(int i=n-m+1;i<=n;i++)
	{
		(res *= i) %= Mod;
	}
	return res;
}
void dfs(int idx,int sum,int maxn,int lst)
{
	if(idx <= 0)
	{
		if(sum > maxn*2)
		{
			ans++;
		}
		return ;
	}
	for(int i=lst+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			dfs(idx-1,sum+a[i],max(maxn*1ll,a[i]),i);
			vis[i] = false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool ais1 = true;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ais1 &= (a[i]==1);
	}
	if(ais1 == true)
	{
		for(int i=3;i<=n;i++)
		{
			(ans += apl(n,i)/apl(i,i)) %= Mod;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,0,0,0);
			ans %= Mod;
		}
	}
	cout << ans%Mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
