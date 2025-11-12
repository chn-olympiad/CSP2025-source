#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	int n,m,i,a[105],l,s,h;
	cin>>n>>m>>s;
	for(i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	if((101-s)%m==0)
	{
		l=(101-s)/m;
	}
	else
	{
		l=(101-s)/m+1;
	}
	if(l%2==0)
	{
		if((101-s)%n==1)
		{
			h=n;
		}
		else if((101-s)%n==0)
		{
			h=1;
		}
		else
		{
			h=(101-s)%n;
		}
	}
	else
	{
		if((101-s)%n==0)
		{
			h=n;
		}
		else
		{
			h=(101-s)%n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
