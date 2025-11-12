#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000],i,k,c,b,t,d,x,q[15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		c=a[1];
	}
	
	for(i=n;i>=1;i--)
	q[++k]=i;
	
	for(i=1;i<=n*m-1;i++)
	{
		for(k=i;k<n*m;k++)
		{
			if(a[k]<=a[k+1])
			{
				b=a[k];
				a[k]=a[k+1];
				a[k+1]=b;
			}
		}
		
	}
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			t=i;
			break;
		}
	}
	
	if(t%n==0)
	{
		x=t/n;
		if(x%2==0)
		cout<<x<<' '<<1;
		
		if(x%2!=0)
		cout<<x<<' '<<n;
		
	}
	
	if(t%n!=0)
	{
		x=t/n;
		d=t%n+1;
		if(x%2!=0)
		{
			cout<<x+1<<' '<<d;
		}
		
		if(x%2==0)
		{
			cout<<x+1<<' '<<q[d];
		}
		
    }
	return 0;
}
