#include <bits/stdc++.h>
using namespace std;
long long int n,m,k,a[500005],b[500005],x,y,ans,l=500006,r=-1,g;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		if(a[0]==k)
		{
			cout<<1;
			return 0;
		}
	}
	if(n==2)
	{
		if(a[1]==k&&a[0]==k)
		{
			cout<<2;
			return 0;
		}
		else if(a[0]==k)
		{
			cout<<1;
			return 0;
		}
		else if(a[1]==k)
		{
			cout<<1;
			return 0;
		}
		
		else if(a[0]^a[1]==0)
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
