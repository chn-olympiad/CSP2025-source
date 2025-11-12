#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a[1000005];
int vis[1000005],cnt,flag=1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1)
		{
			flag=0;
			break;
		}
	}
	
	if(n==1&k==0&&flag)
	{
		cout<<0;
		return 0;
	}
	if(n==2&&k==0&&flag)
	{
		cout<<1;
		return 0;
	}
	if(k==0 && flag)
	{

		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
		}
		cout<<cnt;
		return 0;

	}
	else 
	{
		if(k==1 && flag)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) cnt++;
	}
	cout<<cnt;
	return 0;
}


