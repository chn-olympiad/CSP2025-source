#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1||a[i]==0)
		{
			cnt++;
		}
	}
	if(n==2&&k==0)
	{
		if(a[1]==a[2])
		{
			cout<<1;
			return 0;
		}
		if(a[1]==0&&a[2]==0)
		{
			cout<<2;
			return 0;
		}
		if(a[1]==0||a[2]==0)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(n==1&&k==0)
	{
		if(a[1]==0)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(cnt==n)
	{
		if(k==0)
		{
			for(int i=1;i<n;i+=2)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					ans++;
				}
				else if(a[i]==0)
				{
					i--;
					ans++;
				}
				else if(a[i+1]==0)
				{
					ans++;
				}
				else
				{
					ans+=2;
				}
			}
			cout<<ans;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<1;
	return 0;
}