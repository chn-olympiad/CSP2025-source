#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[10000],num,sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	}
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;--i)
	{
		sum++;
		if(a[i]==num)
		{
			break;
		}	
	}
	if(sum%n==0)
	{
		if(sum/n%2==1)
		{
			c=sum/n;
			r=n;
		}
		else
		{
			c=sum/n;
			r=1;
		}
	}
	else
	{
		if((sum/n+1)%2==1)
		{
			c=sum/n+1;
			r=sum%n;
		}
		else
		{
			c=sum/n+1;
			r=n+1-sum%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;	
} 
