#include <bits/stdc++.h>
using namespace std;
int main()
{
	fropen("polygon","r",stdin);
	fropen("polygon","w",stdout);
	int sum=0;
	int maxx=1000;
	int n,a[1000];
	int i=1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<=n+3;i++)
	{
		if(a[i]<maxx)
		{
			a[i]=maxx+4;
		}
	}
	for(i=0;i<=n+3;i++)
	{
		if(a[i]>maxx)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
