#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000007],h1,h0,vis[10000007],num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			h1++;
		if(a[i]==0)
			h0++;
	}
	if(h1==n)
	{
		if(k==1)
		{
			cout<<n;
		}
		else if(k==0)
		{
			int tot=0,ans=0;
			for(int i=1;i<=n;i++)
			{
				if(i%3==0)
					continue;
				tot++;
				if(tot%2==0)
					ans++;
			}
			cout<<ans;
		}

	}
	else if(h1+h0==n&&h1!=n)
	{
		if(k==1)
		{
			cout<<h1;
		}
		if(k==0)
		{
			long long tot=0,ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					vis[i]=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i+1]==1&&vis[i]==0&&vis[i+1]==0)
				{
					ans++;
					vis[i]=1;
					vis[i+1]=1;
				}
			}
			cout<<ans;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				long long ans=1;
				for(int k=i;k<=j;k++)
				{
					if(vis[k]==0)
					{
						ans=(ans^a[k]);
						vis[k]=1;
					}
				}
				if(ans==k)
				{
					num++;
				}

			}
		}
		cout<<num;
	}
	return 0;
}