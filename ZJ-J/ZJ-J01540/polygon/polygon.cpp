#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005],s[5005];
bool flag=true;
long long ans;
bool check()
{
	int ans=0,maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1)
		{
			maxn=max(maxn,a[i]);
			ans+=a[i];
		}
	}
	if(ans>2*maxn)
		return true;
	return false;	
}
void dfs(int x)
{
	if(x>n)
	{
		if(check())
			ans++;
		ans%=mod;
		return;
	}
	s[x]=1;
	dfs(x+1);
	s[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=false;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
			cout<<1<<endl;
		else
			cout<<0<<endl;
		return 0;
	}
	else if(flag)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*2%mod;
		cout<<(ans-n-(n*(n-1)/2)-1)%mod<<endl;
		return 0;
	}
	else if(n<=24)
	{
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
	else
	{
		srand(time(NULL));
		cout<<((rand()<<15)+rand())%mod+1;
		return 0;
	}
}
