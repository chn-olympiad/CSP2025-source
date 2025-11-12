#include<bits/stdc++.h>
using namespace std;
int a[5000];
int n;
long long ans=0;
void dfs(int m,int l,int sum,int ma)
{
	if(l==m) 
	{
		if((2*a[ma])<sum)
		ans=(ans+1)%998244353;
		return;
	}
	else
	{
		for(int i=ma+1;i<=n-m+l+1;i++)
		dfs(m,l+1,sum+a[i],i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1) 
	{
		for(int i=3;i<=n;i++)
		{
			long long l=1;
			for(int j=1;j<=i;j++)
			{
				l=l*(n-j+1)/j;
				l%=998244353;
			}
			ans+=l;
			ans%=998244353;
		}
		cout<<ans;
	} 
	else
	{
		for(int i=3;i<=n;i++)
		{
			dfs(i,0,0,0);
		}
		cout<<ans;
	}
	return 0;
}


