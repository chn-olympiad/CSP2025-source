#include<bits/stdc++.h>
using namespace std;
int a[10005],s[10005];
bool cmp(int n,int m)
{
	return n>m;
}
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,i,j,c,r;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1],s=0;
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(sum==a[i])
		{
			s=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s==n)
			{
				c=1;
				r=s%n;
			}
			if(s==n+1)
			{
				c=2;
				r=n;
			}
			if(s==2*n+1)
			{
				c=3;
				r=s%n;
			}
			
		}
	}
	if(c%2==0)
			{
				r=n;
			}
			else
			{
				r=s%n;
			}
	cout<<c<<" "<<r;
	return 0;
}
