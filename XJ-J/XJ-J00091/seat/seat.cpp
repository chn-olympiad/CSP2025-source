#include<bits/stdc++.h>
using namespace std;
int a[100000+10];
int ip=1;
bool cmp(int x1,int x2)
{
	if(x1==x2)
	{
		return x1;
	}
	return x1>x2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[0])
		{
			ip++;
		}
	}
	int x=0,y=0;
	if(ip%n==0)
	{
		y=ip/n;
	}
	else
	{
		y=ip/n+1;
	}
	if(y%2==0)
	{
		if(ip%n==0)
		{
			x=n-ip%n;
		}
		else
		{
			x=n-ip%n+1;
		}
		
	}
	else
	{
		if(ip%n==0)
		{
			x=n;
		}
		else
		{
			x=ip%n;
		}
	}
	cout<<y<<" "<<x;
    return 0;
}
