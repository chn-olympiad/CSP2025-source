#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sumd,wz,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			sumd++;
		}
	}
	wz=sumd+1;
	if(wz%n==0)
	{
		c=wz/n;
		cout<<c<<' ';
	}
	if(wz%n!=0)
	{
		c=wz/n+1;
		cout<<c<<' ';
	}
	if(c%2==0)
	{
		r=n-wz%n+1;	
		cout<<r;
	}
	if(c%2!=0)
	{
		if(wz%n==0)
		{
			r=n;
		}
		else r=wz%n;
		cout<<r;
	}
	
	return 0;
}
