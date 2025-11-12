#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	if(sum==n)
	{
		cout<<n/2;
		return 0;
	}
	int j=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1||a[i]!=0)
				break;
			if(a[i]==1)
				j++;
		}
		cout<<j;
		return 0;
	}
	if(k==0)
	{
		int q=0;
		if(a[1]==0)
			q++;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]&&a[i]!=0)
				j++;
			if(a[i]==0)
				q++;
		}
		cout<<j+q;
		return 0;		
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]^a[i+1])==k&&a[i]!=k&&a[i+1]!=k)
		{
			t++;
			i++;
		}
		if(a[i]==k)
			t++;
	}
	cout<<t;
	return 0;
}
