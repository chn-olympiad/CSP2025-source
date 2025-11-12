#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,k,a[N],ans=0,xo[N];
long long f(long long x,long long y)
{
	if(x==y)
	{
		return 0;
	}
	long long a=x,b=y,cnt=1,sum=1;
	while(max(a,b)!=0)
	{
		if((a%2==1 && b%2==0) || (a%2==0 && b%2==1))
		{
			xo[cnt]=1;
		}
		else
		{
			xo[cnt]=0;
		}
		a/=2;
		b/=2;
		cnt++;
	}
	cnt--;
	for(long long i=1;i<=cnt;i++)
	{
		sum+=xo[i]*pow(2,i-1);
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long l=2;l<=n+1;l++)
	{
		for(long long r=l-1;r<=n;r++)
		{
			long long cnt;
			cnt=a[l-1];
			for(long long i=l;i<=r;i++)
			{
				cnt=f(cnt,a[i]);
			}
			if(cnt==k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
