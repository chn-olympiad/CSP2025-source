#include<iostream>
using namespace std;
int n,m,a[100000];
int main()

{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==a[1])
			{
				cout<<i<<" "<<j;
			}
		}
		
	}
	return 0;
}
