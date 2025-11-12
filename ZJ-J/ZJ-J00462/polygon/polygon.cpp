#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int mod=998244353;
int n,a[N];
ll s[N],ans;
void dfs(int x,ll sum,int mx,int cnt)
{
	if(x==n+1)
	{
		if(cnt>=3)
		{
			if(sum>2*mx)
			{
//				cout<<sum<<" "<<mx<<" "<<cnt<<'\n';
				ans++,ans%=mod;
			}
		}
		return;
	}
	dfs(x+1,sum+a[x],a[x],cnt+1);
	dfs(x+1,sum,mx,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	if(s[n]==n)
	{
		ll ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=mod;
		}
		cout<<ans-1-n-n*(n-1)/2<<'\n';
	}
	else if(n<=20)
	{
		ans=0;
		dfs(1,0,0,0);//i,sum,mx,chose
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}