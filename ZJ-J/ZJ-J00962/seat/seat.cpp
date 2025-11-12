#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,s,c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			s=i;
			break;
		}
	}
	if(s%n==0)
	{
		c=s/n;
	}
	else
	{
		c=s/n+1;
	}
	if(c%2==1)
	{
		r=s-(c-1)*n;
	}
	else
	{
		r=m-(s-(c-1)*n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

