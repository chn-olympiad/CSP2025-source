#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const long long Mod=998244353;
ll n;
ll a[N];
bool vis[N];
ll h=0;
void check(int ii)
{
	int sum=0;
	int pos=0;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==1)
			sum+=a[i];
	}
	if (sum>a[ii]*2);
		h=(h+1)%Mod;
	return;
}
void dfs(int i,int num)
{
	if (i==n+1)
	{
		return;
	}
	if (num>=3)
	{
		check(i);
		return;
	}
	vis[i]=1;
	dfs(i+1,num+1);
	vis[i]=0;
	dfs(i+1,num);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>2*a[n])
			cout<<1;
		else
			cout<<0;
	}
	else if (a[n]==1)
	{
		ll ans=0;
		for (int i=3;i<=n;i++)
		{
			ll aa=1;
			for (int j=n;j>i;j--)
				aa=aa*j%Mod;
			for (int j=i;j>=1;j--)
				aa=aa/j;
			ans+=aa;
		}
		cout<<ans;
	}
	else
	{
		dfs(1,1);
		cout<<h;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
