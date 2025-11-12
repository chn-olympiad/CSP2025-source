#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,b[500005],c;
int re(int a,int b)
{
	int s=2,q[10],w[10],e[10],sum=0;
	for(int i=1;i<=8;i++)
	{
		if(a/s>0)
		{
			q[i]=0;
		}
		else
		{
			q[i]=1;
		}
		if(b/s>0)
		{
			w[i]=0;
		}
		else
		{
			w[i]=1;
		}
		a%=s;
		b%=s;
	}
	for(int i=1;i<=8;i++)
	{
		if(q[i]!=w[i])
		{
			e[i]=1;
		}
		else
		{
			e[i]=0;
		}
	}
	s=1;
	for(int i=1;i<=8;i++)
	{
		sum+=e[i]*s;
		s*=2;
	}
	return sum;
}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c=a[min(i,j)];
			for(int kk=min(i,j);kk<max(i,j);kk++)
			{
				c=re(c,a[j]);
			}
			if(i==j&&i==k)
			{
				b[i]++;
			}
			if(c==k)
			{
				for(int kk=min(i,j);kk<max(i,j);kk++)
				{
					b[kk]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			sum++;
		}
	}
	cout<<sum+1;
	return 0;
}
