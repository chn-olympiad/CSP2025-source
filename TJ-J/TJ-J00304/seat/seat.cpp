#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("seat.in","a",stdin);
	//freopen("seat.out","c",stdout);
	//freopen("seat.out","r",stdout);
	int a[1000];
	int n,m,p=1,c,r;
	cin>>n>>m;
	cin>>a[1000];
	for(int i=1;i<=n*m;i++)
	{
		if(a[0]<=a[i] || a[0]<=a[i+1])
		{
		 	p++;	
		}
	}
	if(n%2==0)
	{
		if(p%n==0)
		{
			c=p/n;
			r=m-p/n+1;
		}
	else
		{
			c=p/n+1;
			r=p/n+1;
		}
	}
	else
	{
	if(p%n==0)
		{
			c=p/n+1;
			r=m-p/n;
		}
	else
		{
			c=p/n+1;
			r=p/n+1;
		}
	}
	cout<<c<<' '<<r<<p;
	return 0;
}
