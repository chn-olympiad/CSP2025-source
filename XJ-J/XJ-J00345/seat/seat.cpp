#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,b;
	cin>>n>>m;
	int a[1000005];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]=s)
		{
			b=i;
			break;
		}
	}
	if(b/n%2==0)
	{
		if(b%n==0)
		{
			cout<<b/n;
		}
		else
		{
			cout<<b/n+1;
		}
		cout<<" ";
		cout<<n-b%n+1;
	}
	if(b/n%2==1)
	{
		if(b%n==0)
		{
			cout<<b/n;
		}
		else
		{
			cout<<b/n+1;
		}
		cout<<" ";
		cout<<b%n+1; 
	}
	return 0;
}
