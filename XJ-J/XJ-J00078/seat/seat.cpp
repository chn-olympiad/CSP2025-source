#include<bits/stdc++.h> 
using namespace std;
int cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	int sum=n*m,l,h;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	 } 
	int xr=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==xr)
		{
			xr=i;//  "xr"里面是他的排名 
		}
	}
	if(xr<=n)
	{
		cout<<1<<" "<<xr;
	}
	else 
	{
		if(xr%n==0)
		{
			l=xr/n;
			if(l%2==1)
			{
				h=n;
			}
			else
			{
				h=1;
			}
			cout<<l<<" "<<h;
			return 0;
		}
		else
		{
			l=xr/n+1;
		}
		if(l%2==1)
		{
			h=xr%n;
			cout<<l<<" "<<h;
			return 0;
		}
		else
		{
			h=(n+1)-xr%n;
			cout<<l<<" "<<h;
			return 0;
		}
	}
	
	
	return 0;
}
