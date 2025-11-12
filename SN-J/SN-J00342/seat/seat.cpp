#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,w;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			t=a[i];
		}
	}
	for(int i=n*m-1;i>=0;i--)
	{
		for(int j=n*m-1;j>=0;j--)
		{
			if(a[j]>a[j-1]&&j-1>=0)
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==t)
		{
			w=i+1;
		}
	}
	int z=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(z==w)
			{
				if(i%2!=0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				if(i%2==0)
				{
					cout<<i<<" "<<n-j+1;
				}
			}
			z++;
		}
	}
	return 0;
}
