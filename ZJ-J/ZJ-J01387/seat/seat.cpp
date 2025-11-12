#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans;
bool cmp(long long x,long long y)
{
	return x>y;
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
	long long x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			ans=i;
		}
	}
	long long c=ans/n,b=ans%n;
	if(b==0)
	{
		if(c%2==1)
		{
			cout<<c<<" "<<n;
		}
		else
		{
			cout<<c<<" "<<1;
		}
	}
	else
	{
		if(c%2==1)
		{
			cout<<c+1<<" "<<n-b+1;
		}
		else
		{
			cout<<c+1<<" "<<b;
		}
	}
	return 0;
}