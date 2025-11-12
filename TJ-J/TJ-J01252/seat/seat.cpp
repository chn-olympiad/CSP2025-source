#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int I=a[1];
	int order=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(I==a[i])
		{
			order=i;
		}
	}
	int x=0,y=0;
	if(order%n!=0)
	{
		y=(order/n)+1;
		if(y%2!=0)
		{
			x=order%n;
		}
		else
		{
			x=n-(order%n)+1;
		}
	}
	else
	{
		y=order/n;
		if(y%2!=0)
		{
			x=n;
		}
		else
		{
			x=1;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}

