#include<iostream>
using namespace std;
int a[10005],f[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		f[1]=1;
		f[i+1]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(f[j],f[j+1]);
			}
		}
	}
	while(m--)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[j]==1)
			{
				s=1;
				r=j;
			}
		}
		if(s==0)
		{
			c++;
			
		}
		else
		{
			c=1;
			break;
		}
	}
	if(c%2==0)
	{
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
