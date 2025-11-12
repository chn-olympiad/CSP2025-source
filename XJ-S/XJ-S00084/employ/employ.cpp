#include<bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		int z=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||a[i]==0)
			{
				z=1;
			}
		}
		if(z==0)
		{
			sum=1;
			for(int i=1;i<=n;i++)
			{
				sum=sum*i%998244353;
			}
		}
		cout<<sum;
	}
	if(m==1)
	{
		int z=0,sum=0,y=0,x=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
				l=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&z==0)
			{
				y=i;
				z=1;
			}
			if(a[i]==0)
			{
				x++;
			}
		}
		if(l==0)
		{
			cout<<sum;
			return 0;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=y;i++)
		{
			if(a[i]!=0&&a[i]<=x)
				x++;
		}
		if(n<=x)
		{
			cout<<sum;
			return 0;
		}
		sum=1;
		for(int i=1;i<=n;i++)
		{
			if(i!=y)
				sum=sum*i%998244353;
			else
			{
				if(i>n-x)
				{
					sum=sum*(n-x)%998244353;
				}
				else
					sum=sum*i%998244353;
			}
		}
		cout<<sum;
	}
	sort(a+1,a+n+1);
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			x++;
	}
	for(int i=1+x;i<=n;i++)
	{
		if(a[i]<=x||s[i-1]=='0')
			x++;
	}
	cout<<x<<" ";
	int sum=0;
	if(x>=m)
		cout<<sum;
	else
	{
		sum=1;
		for(int i=1;i<=n-m;i++)
		{
			sum=sum*i;
		}
		for(int i=1;i<=m;i++)
		{
			sum=sum*i;
		}
		cout<<sum;
	}
	return 0;
} 
