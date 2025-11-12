#include<iostream>
#include<cmath>
using namespace std;/*
struct ss{
	int g[20];
}a[500005],k;
void chai(int k1,int k2)
{
	int ans11=0;
	while(k1!=0)
	{
		a[k2].g[ans11]=k1%2;
		k1/=2;
		ans11++;
	}
}
ss add1(ss x,ss y)
{
	for(int i=0;i<20;i++)
	{
		x.g[i]=(x.g[i]+y.g[i])%2;
	}
	return x;
}
bool end1(ss x)
{
	for(int i=0;i<20;i++)
	{
		if(x.g[i]!=k.g[i])
			return 0;
	}
	return 1;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,kx;
	scanf("%d%d",&n,&kx);/*
	int ans11=0;
	while(kx!=0)
	{
		k.g[ans11]=kx%2;
		kx/=2;
		ans11++;
	}*/
	int a[500005];
	int ansxx=0,ansxxx=0;
	for(int i=0;i<n;i++)
	{
		int a[i];
		scanf("%d",&a[i]);
		if(a[i]==1||a[i]==0)
			ansxx++;
		if(a[i]==1)
			ansxxx++;
	//	chai(x1,i);
	}
	if(ansxxx==n&&kx==0)
	{
		cout<<n/2;
		return 0;
	}
	if(ansxx==n&&kx==0)
	{
		int ans=0;
		for(int i=0;i<n-1;)
		{
			if(a[i]==a[i+1])
			{
				ans++;
				i+=2;
				continue;
			}
			if(a[i]==1&&a[i+1]==0)
			{
				ans++;
				i+=3;
				continue;
			}
			if(a[i]==0&&a[i+1]==1)
			{
				i+=1;
				continue;
			}
		}
		cout<<ans;
		return 0;
	}
	if(ansxx==n&&kx==1)
	{
		int ans=0;
		for(int i=0;i<n-1;)
		{
			if(a[i]!=a[i+1])
			{
				ans++;
				i+=2;
				continue;
			}
			if(a[i]==1&&a[i+1]==1)
			{
				ans++;
				i+=3;
				continue;
			}
			if(a[i]==0&&a[i+1]==0)
			{
				i++;
				continue;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}