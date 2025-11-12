#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[101];
int c,r,p;
bool cmpp(int a,int b);
void findd(int ee,int l,int r);
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int tt=a[1];
	sort(a+1,a+n*m,cmpp);
	findd(tt,1,n*m);
	c=p/n+1;
	if(p%n==0)
	{
		c--;
	}
	if(c%2==1)
	{
		r=p%n;
		if(r==0)r=n;
	}
	else
	{
		r=n-p%n+1;
		if(p%n==0)r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
bool cmpp(int a,int b)
{
	return a>b;
}
void findd(int ee,int l,int r)
{
	if(l>r)return;
	int midd=(l+r)/2;
	if(ee==a[midd])
	{
		p=midd;
		return;
	}
	if(ee>a[midd])
	{
		findd(ee,l,midd-1);
	}
	if(ee<a[midd])
	{
		findd(ee,midd+1,r);
	}
}
