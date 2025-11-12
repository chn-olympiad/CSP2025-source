#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[500010];
int sum[500010];
int flag,cnt;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0||a[i]==1)
		{
			
		}
		else
		{
			flag=1;
		}
		if(a[i]==0) 
		{
			cnt++;
		}
		if(i==1)
		{
			sum[i]=a[i];
		}
		else
		{
			sum[i]=sum[i-1]^a[i];
		}
	}
	if(flag==1)
	{
		if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(ans==0&&a[i]==1)
				{
					ans=1;
				}
				else if(ans>0&&a[i]==1)
				{
					ans++;
				}
				else
				{
					ans=0;
				}
				if(ans==2)
				{
					cnt++;
					ans=0;
				}
			}
			cout<<cnt<<endl;
		}
		else
		{
			cout<<n-cnt<<endl;
		}
		return 0;
	}
	int last=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=last;j<=i;j++)
		{
			if(i==j)
			{
				if(a[i]==k)
				{
					ans++;
					last=i;
					break;
				}
			}
			else if(j==0)
			{
				if(sum[i]==k)
				{
					ans++;
					last=i;
					break;
				}
			}
			else if((sum[i]^sum[j])==k)
			{
				ans++;
				last=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
