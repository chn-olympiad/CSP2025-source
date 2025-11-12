#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k=1,a,b,c,d,ansx,ansy;
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&b);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%lld",&a);
		if(a>b)
			k++;
	}
	c=k/n;
	d=k%n;
	if(c*n!=k)
		c++;
	if(d==0)
		d=n;
	if(c%2==1)
	{
		ansx=d;
		ansy=c;
	}
	else
	{
		ansx=n-d+1;
		ansy=c;
	}
	printf("%lld %lld",ansy,ansx);
	return 0;
}