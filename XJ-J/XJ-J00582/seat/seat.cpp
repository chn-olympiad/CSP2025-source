#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(long long x,long long y)
{
	return x>y;
}
long long hhh(long long a,long long b)
{
	if(a%b==0)return a/b;
	else
	{
		return a/b+1;
	}
}
long long hh(long long a,long long b,long long c)
{
	if(a%b==0)return a;
	if(c%2==1)return a%b;
	else
	{
		return b-a%b+1;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			s=i;
			break;
		}
	}
	long long c=hhh(s,n);
	long long r=hh(s,n,c);
	cout<<c<<' '<<r;
	return 0;
}
