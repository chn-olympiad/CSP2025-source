#include<bits/stdc++.h>
using namespace std;
long long a[1000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	return 0;
	for(i=1;i<=n;i++)
	{
		j=a[i]+a[i+1]+a[i+2];
		k=a[i+1]+a[i+2]+a[i+3];
		if(j>k)
		{
			cout<<j;
		}
		if(j<k)
		{
			cout<<k;
		}
	}
}
