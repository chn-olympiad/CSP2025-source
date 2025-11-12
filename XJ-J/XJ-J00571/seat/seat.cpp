#include<bits/stdc++.h>
using namespace std;
int a[125],t=0,num=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,k,c=1,r=1;
	cin>>n>>m;
	if(n==1)
	{
		cout<<m<<" "<<1;
		return 0;
	}
	if(m==1)
	{
		cout<<1<<" "<<n;
		return 0;
	}
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		num=a[1];
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=i;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=1;i<=n*m;i++)
	{
		if(num==a[i])
		{
			cout<<c<<" "<<r;
		}
		else
		{
			if(r==0 || r==n)
			{
				c++;
			}
			if(c%2==0)
			{
				r--;
			}
			else
			{
				r++;
			}
			
		}
	}
	return 0;
}
