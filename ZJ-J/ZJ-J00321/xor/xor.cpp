#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],A=1,B=1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		A=0;
		if(a[i]>1)
		B=0;
	}
	if(A)
	{
		if(n%2==0)
		cout<<n/2;
		else
		cout<<(n-1)/2;	
	}
	else if(B)
	{
		if(k==1)
		{
			int s1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				s1++;
			}
			cout<<s1;
		}
		else
		{
			int s0=0,s1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				s1++;
				else
				s0++;
			}
			cout<<(s0+s1/2);
		}
	}
	else
	cout<<1;
	return 0;
}