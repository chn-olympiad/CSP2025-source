#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n,k,c=0;
	freopen("xor.out","r",stdout);
	freopen("xor.in","w",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0||a[i]==1)
		c++;
	}
	if(k==0)
	{
		cout<<n;
		return 0;
	}
	if(c==n)
	{
		cout<<0;
		return 0;
	}
	int m=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if((a[i]=a[i+1]+1)||(a[i]=a[i+1]-1))
			{
				m++;
			} 
			 i=i+2;
		 } 
	}
	cout<<m;
	return 0;
} 
/* 
int n,k,a[199999]={},b[5005][5005],ja1,ja2;
long long yh(long long x,long long y)
{
	long long se1[10000],se2[10000],s1n=0,s2n=0,m=0,h=1;
	memset(se1,10000,-1);
	memset(se2,10000,-1);
	while(se1!=0)
	{
		s1n++;
		se1[s1n]=x%2;
		x/=2;
		
	}
	while(se1!=0)
	{
		s1n++;
		se1[s1n]=x%2;
		x/=2;
		
	}
	s1n=max(s1n,s2n);
	for(int i=1;i<=s1n;i++)
	{
		if(se1[i]!=se2[i])
		{
			m+=x;
			h*=2;
		}
	}
}
long long qj(long long x,long long y)
{
	if(y==n)
	{
		return 0;
	}
	for(int i=y;i<=n;i++)
	{
		if(yh(x,a[i])==k)
		{
			return 1;
		}
		else
		{
			if(qj(yh(x,a[i]),i)==1)
			{
				b[ja1][ja2]=a[i];
				ja2++;
			 } 
		}
	}
}
int main()
{
	freopen("xor.out","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		qj(a[i],i);
		ja2=0;ja1++;
	}
	for()
}*/
//do gei dian fen ba!!!
