#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll ans,n,a[10010],maxx1,tot1,tot2,tot;
void dfs(int pos,ll sum,ll maxx,int step)
{
	maxx=max(maxx,a[pos]);
	if(sum>maxx*2&&step>=3) 
	{
		if(ans>=998244353) ans=0;
		ans++;
		
	}
	if(step>=n) 
	{
		return ;
	}
	for(int i=pos+1;i<=n;i++)
	{
		step++;
		dfs(i,sum+a[i],maxx,step);
		
	}
	return ;
	
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxx1=max(maxx1,a[i]);
	}
	if(maxx1==1)
	{
		for(int i=3;i<=n;i++)
		{
			tot1=1;
			tot2=1;
			for(int j=1;j<=i;j++)
			{
				tot1*=n-j+1;
				tot2*=j;
				if(tot1>1e16)
				{
					tot1/=tot2;
					tot2=1;
					tot1%=998244353;
				}
				
			}
			
			tot+=tot1/tot2;
			if(tot>998244353)
			{
				tot%=998244353;
			}
			
		}
		cout << tot;
		return 0;
	}
	for(int i=1;i<=1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dfs(j,a[j],j,1);
		}
	}
	cout << ans%998244353;
	
	
	
	
	return 0;
}




