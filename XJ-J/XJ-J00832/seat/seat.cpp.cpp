#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s,c,r,n,m,a[105];
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		s=a[1];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i+1]>a[i])
		{
			int k=a[i];
			a[i]=a[i+1];
			a[i+1]=k;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			if(i>m)
			{
				r=i/m;
				c=r;
			}
			else
			{
				c=1;
				r=i;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
