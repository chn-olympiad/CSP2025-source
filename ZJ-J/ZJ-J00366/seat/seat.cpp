#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
int a[101],b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]<a[j+1])
			{
				int t1=a[j],t2=b[j];
				a[j]=a[j+i];
				a[j+i]=t1;
				b[j]=b[j+1];
				b[j+1]=t2;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==1)
		{
			k=i;
			break;
		}
	}
	x=k/n;
	y=k%n;
	if(y==0)
	{
		if(x%2==0)
		{
			cout<<x<<" "<<1;
		}
		else
		{
			cout<<x<<" "<<n;
		}
	}
	else
	{
		if(x%2==0)
		{
			cout<<x+1<<" "<<y;
		}
		else
		{
			cout<<x+1<<" "<<n-y+1;
		}
	}
	return 0;
}