#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],r,x,y;
int main()
{
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=i;j--)
		{
			if(a[j]>a[j-1])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			int x=i/n+1,y=i%n;
			if(x%2==0)
			{
				if(i%n==0)
				{
					cout<<x-1<<" "<<n;
				}
				else
				{
					cout<<x<<" "<<n-y+1;
				}
			}
			if(x%2==1)
			{
				if(i%n==0)
				{
					cout<<x-1<<" "<<"1";
				}
				else
				{
					cout<<x<<" "<<y;
				}
			}	
		}
	}
	return 0;
}
