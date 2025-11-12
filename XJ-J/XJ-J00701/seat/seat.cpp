#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s,n,m,a[105],y,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int j=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==j)
		{
			s=n*m-i+1;
			break;
		}
	}
	x=ceil(s*1.0/n);
	int y2=s%n;
	if(x%2==0)
	{
		if(y2==n-1)
		{
			y=n;
		}
		else
		{
			y=n-y2;
		}
	}
	else
	{
		if(y2==0)
		{
			y=n;
		}
		else
		{
			y=0+y2;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
} 
