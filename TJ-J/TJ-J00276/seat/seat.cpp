#include <bits/stdc++.h>
using namespace std;
int a[1000];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1);
	int g;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==f)
		{
			g=n*m-i+1;
		}
	}
	if(g%n==0)
	{
		int o=g/n;
		if(o%2==0)
		{
			cout<<o<<" "<<1;
		}
		else
		{
			cout<<o<<" "<<n;
		}
	}
	else
	{
		int u=g/n;
		if(u%2==0)
		{
			cout<<u+1<<" "<<g%n;
		}
		else
		{
			cout<<u+1<<" "<<n+1-g%n;
		}
	}
	return 0;
}
