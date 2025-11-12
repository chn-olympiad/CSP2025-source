#include<bits/stdc++.h>
using namespace std;
long long xor1(long long a,long long b)
{
	long long c=0;
	for(long long i=0;;i++)
	{
		if(a/pow(10,i)==0&&b/pow(10,i)==0)
		{
			break;
		}
		if((a/pow(10,i)-a/pow(10,i+1)*10)==0&&(b/pow(10,i)-b/pow(10,i+1)*10)==1)
		{
			c+=pow(10,i);
		}
		if((a/pow(10,i)-a/pow(10,i+1)*10)==1&&(b/pow(10,i)-b/pow(10,i+1)*10)==0)
		{
			c+=pow(10,i);
		}
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,answer=0,k1=0;
	cin>>n>>k;
	long long a[n+1],b[n+1];
	for(long long i=0;;i++)
	{
		if(k==0)
		{
			break;
		}
		k1+=(k%2*pow(10,i));
		k/2;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		long long c=a[i];
		b[i]=0;
		for(long long j=0;;j++)
		{
			if(c==0)
			{
				break;
			}
			b[i]+=(c%2*pow(10,j));
			c/2;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=n;j>=i;j--)
		{
			long long q=0;
			for(long long w=i;w<=j;w++)
			{
				q=xor1(q,b[i]);
			}
			if(q==k1)
			{
				answer++;
			}
		}
	}
	cout<<answer;
	return 0;
}