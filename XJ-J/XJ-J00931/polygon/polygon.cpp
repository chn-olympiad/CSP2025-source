#include <bits/stdc++.h>
using namespace std;
long long a[5010],b[5010];
long long cnt=0,posb=0;
void er(long long n)
{
	cnt=0;
	posb=0;
	memset(b,0,sizeof(b));
	long long pos=0;
	while(n!=0)
	{
		++pos;
		if(n%2==1)  {
		cnt++;
		b[++posb]=a[pos];
		}
		n/=2;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long tot=0;
	for(long long i=1;i<=1<<n;i++)
	{
		er(i);
		if(cnt<3)  continue;
		long long sum=0,maxn=0;
		for(long long j=1;j<=cnt;j++)
		{
			sum+=b[j];
			maxn=max(maxn,b[j]);
		}
		if(maxn*2<sum)
		{
			tot=(tot+1)%998244353;
		}
	}
	cout<<tot;
	return 0;
}
