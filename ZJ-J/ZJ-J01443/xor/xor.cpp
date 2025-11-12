#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long k;
long long a[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)sum++;
		}
		cout<<sum;
		return 0;
	}
	if(k==1)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int o=1;o<=n;o++)
	{
		long long cnt=0;
		long long sum=0;
		for(int i=o;i<=n;i++)
		{
			cin>>a[i];
			cnt^=a[i];
			if(cnt==k)
			{
				sum++;
				cnt=0;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
