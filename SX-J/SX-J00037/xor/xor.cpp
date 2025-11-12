#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],ans,n,k,f[500005];
ll check()
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			sum++;
			f[i]=1e9;
			continue;
		}
		for(int j=i;j>=1;j--)
		{
			if(f[j]==1e9) break;
			f[j]^=a[i];
			if(f[j]==k)
			{
				f[i]=1e9;
				sum++;
				break;
			}

		}
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<check();
	return 0;
}
