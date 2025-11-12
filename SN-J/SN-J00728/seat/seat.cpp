#include<bits/stdc++.h>
using namespace std;
int n,m,R,c,r,a[105],sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		sum++;
		if(a[i]==R)
		{
			break;
		}
	}
	if(sum%n!=0)
	{
		c=sum/n+1;
	}
	else
	{
		c=sum/n;
	}
	if(c%2==0)
	{
		if(sum%n==0)
		{
			r=1;
		}
		else
		{
			r=n-(sum%n)+1;
		}
	}
	else
	{
		if(sum%n==0)
		{
			r=n;
		}
		else
		{
			r=sum%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
