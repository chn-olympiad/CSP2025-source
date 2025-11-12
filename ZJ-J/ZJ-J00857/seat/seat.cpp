#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,b,d;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==b)
		{
			d=n*m-i;
			break;
		}
	}
	c=d/n;
	if(d%n!=0)
	{
		c++;
	}
	r=d%n;
	if(r==0)
	{
		r=n;
	}
	if(c%2==0)
	{
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}