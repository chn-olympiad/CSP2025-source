#include<bits/stdc++.h>
using namespace std;
struct st
{
	long long int tx=0,ty=0;
}q[100005];
long long int n,k,a[600009],b[600009],c[100000],d[100000],e[100000],g=1;
int fun(long long int t,long long int v)
{
	int k=0,i=0,j=0,x=0,sum=0;
	memset(c,0,100000);
	memset(e,0,100000);
	memset(d,0,100000);
	while(t!=0)
	{
		c[++k]=t%2;
		t/=2;
	}
	
	while(v!=0)
	{
		d[++i]=v%2;
		v/=2;
	}
	
	for(j=1;j<=max(i,k);j++)
	{
		if(d[j]==c[j])
		{
			e[++x]=0;
		}
		else
		e[++x]=1;
	}
	
	for(i=0;i<=x;i++)
	{
		sum+=(int)pow(2,i)*e[i];
	}
	
	return sum;
}
int fun1(long long int x,long long int y)
{
	long long int i,j,s;
	for(i=x;i<=y;i++)
	{
		if(i==x)
		s=b[i];
		s=fun(s,b[i]);
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int i=0,j=0,t;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	g=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(q[g].ty<i&&fun1(i,j)==k)
			{
				q[++g].tx=i;
				q[++g].ty=j;
			}
		}
	}
	
	cout<<g;
	return 0;
}
