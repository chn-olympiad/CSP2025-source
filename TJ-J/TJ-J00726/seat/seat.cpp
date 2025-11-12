#include <bits/stdc++.h>
using namespace std;
int main()
{
	froopen("seat.in","r",stdin)
	foopen("seat.out","w",stdout)	
	int n,m;
	cin>>n>>m;
	int a[100000];
	for(int i=1;i<=a[n*m];i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=a[n*m];i++)
	{
		if(a[i]<a[i+1])
		{
			int num=0;
			num=a[i];
			a[i]=a[i+1];
			a[i+1]=num;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i,j];
			if(a[i-1]<a[1] || a[1]>a[i+1])
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
