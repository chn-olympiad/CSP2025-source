#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1100];
int sc;
bool cmp(int a,int b)
{
	return a>b;
}
int p;
int c,r;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;++i)
	{
		scanf("%lld",&a[i]);
	}
	sc = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i] == sc)
		{
			p = i;
			break;
		}
	}
//	for(int i=1;i<=n*m;++i)
//	{
//		printf("%lld ",a[i]);
//	}
//	printf("\n%lld\n",p);
	if(p%n == 0)
	{	
		c = p/n;
		if(c%2 == 0)
		{
			r = 1;	
		}
		else
		{
			r = m;
		}
	}
	else
	{
		c = p/n+1;
		if(c%2 == 0)
		{
			r = c*n - p+1;
		}
		else
		{
			r = p - (c-1)* n;
		}
	}
	printf("%lld %lld",c,r);
	return 0;
}
