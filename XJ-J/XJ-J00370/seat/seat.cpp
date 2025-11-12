#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,a[105],m,n,r,c,s;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			break;
		}
	}
	r=i%n;
	s=i/n;
	if(r==0)
	{
		cout<<s<<' ';
		if(s%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<s+1<<' ';
		if(s%2==1)
		{
			cout<<n-r+1;
		}
		else
		{
			cout<<r;
		}
	}
	return 0;
}
