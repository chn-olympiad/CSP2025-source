#include<bits/stdc++.h>
using namespace std;
int a[105],s[105];
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,c,r,y;
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++)
	{
		s[i]=a[i];
	}
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(s[0]==a[i])
		{
			x=n*m-i;
			break;
		}
	}
	if(x%2!=0)
	{
		c=x/m+1;
	}
	else
	{
		c=x/m;
	}
	if(c%2!=0)
	{
		
		if(x%m==0)
		{
			r=m;
		}
		else
		{
			r=x%m;
		}
	}
	else
	{
		y=x/m;
		r=m+1-y;
	}
	cout<<c<<" "<<r;
	return 0;
}
