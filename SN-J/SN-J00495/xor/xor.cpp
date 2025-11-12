#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long two(int a)
{
	long long a1=0,i=0;
	while(a>pow(2,i))
	{
		i++;
	}
	while(a>0)
	{
		if(a>=pow(2,i))
		{
			a1+=pow(10,i);
			a-=pow(2,i);
		}
		i--;
	}
	return a1;
}
int yh(int a,int b)
{
	long long a1,b1,sum=0;
	a1=two(a);
	b1=two(b);
	long long i=0;
	while(a1>=pow(10,i)||b1>=pow(10,i))
	{
		if(a1/int(pow(10,i))%10+b1/int(pow(10,i))%10==1)
		{
			sum+=pow(10,i);
		}
		i++;
	}
	int s=sum;
	sum=0;
	int j=0;
	while(s!=0)
	{
		if(s/int(pow(10,j))%10==1)
		{
			sum+=pow(2,j);
			s-=pow(10,j);
		}
		j++;
	}
	return sum;
}
int main()
{
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int s=0,sum=0;
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				sum++;
			}
			if(a[i]==a[i+1]==1)
			{
				sum++;
				i++;
			}
		}
	}
	else if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				sum++;
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(s==k&&s!=0||a[i]==k)
			{
				sum++;
				s=0;
			}
			s=yh(s,a[i]);
		}
	}
	cout<<sum;
	return 0;
}
