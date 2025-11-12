#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum,d,a[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=1&&a[i]!=0)
		{
			d=2;
			break;
		}
		else if(a[i]!=1&&a[i]==0) d=1;
	}
	if(k==0&&d==0) return cout<<n/2,0;
	else if(k==1&&d==0) return cout<<n,0;
	else if(k==0&&d==1)
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]==0) sum++;
			else if(a[i]==1)
			{
				if(a[i+1]==1)
				{
					sum++;
					i++;
				}
			}
		}
		return cout<<sum,0;
	}
	else if(k==1&&d==1)
	{
		for(int i=1;i<=n;++i)
			if(a[i]==1) sum++;
		return cout<<sum,0;
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]==k) sum++;
		}
		cout<<sum;
	}
	return 0;
}
