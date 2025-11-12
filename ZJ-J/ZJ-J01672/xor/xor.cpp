#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500100],b[500100];
long long l,r,ans;
bool f;
long long qj(long long x,long long y)
{
	if(l>1)return b[r]^b[l-1];;
	if(l==1)return b[r];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=1;
		if(i==1)
		{
			b[i]=a[i];
			continue;
		}
		b[i]=b[i-1]^a[i];
	}
	if(n==1&&k!=a[1])
	{
		cout<<0;
		return 0;
	}
	if(f==0&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(f==0&&k==1)
	{
		cout<<n;
		return 0;
	}
	
	
	l=0,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(qj(i,j)==k)ans++;
			}
		}
		if(ans>mid)
		{
			l=mid+1;
		}
		else 
		{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
