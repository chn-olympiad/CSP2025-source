#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],cnt,st,x=1,y=1;
bool f;
bool cmp(long long x,long long y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cnt=n*m;
	for(long long i=1;i<=cnt;i++) scanf("%lld",a+i);
	st=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++)
	{
		if(st==a[i])
		{
			printf("%lld %lld",x,y);
			return 0;
		}
		if(!f)
		{
			y++;
			if(y==n+1)
			{
				x++;
				y=n;
				f=1;
			}
		}
		else
		{
			y--;
			if(y==0)
			{
				x++;
				y=1;
				f=0;
			}
		}
	}
	return 0;
}
