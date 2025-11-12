#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=998244353;
int n,k,a[5005],cnt1,cnt0;

signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt1++;
		}
		else if(a[i]==0)
		{
			cnt0++;
		}
	}
	int ans=0;
	if(cnt1+cnt0==n)
	{
		if(k==1)
		{
			cout<<cnt1;
		}
		else if(k==0)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					sum++;
				}
				else if(a[i]==0)
				{
					ans+=sum/2;
					sum=0;
				}
			}
			cout<<ans+cnt0;
		}
	}
	return 0;
}
