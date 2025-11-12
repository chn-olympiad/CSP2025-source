#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxx=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n==3)
	{
		if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&a[2]+a[3]>a[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
} 
