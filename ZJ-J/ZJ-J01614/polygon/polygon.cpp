#include<bits/stdc++.h>
using namespace std;
#define goodbye return 0;
int a[50001];
int b[50001];
int n,sum=0;
int fun(int m)
{
	int num=n;
	if(b[m]!=n)return 0;
	for(int i=m;i>=2;i--)
	{
		if(b[i]!=num)return 0;
		num--;
	}
	return 1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int m=3;m<=n;m++)
	{
		for(int i=1;i<=m;i++)b[i]=i;
		int f=1;
		while(f)
		{
			int s=0,ma=0;
			for(int i=1;i<=m;i++)
			{
				ma=max(ma,a[b[i]]);
				s+=a[b[i]];
			}
			if(s>2*ma)
			{
				sum++;
				sum%=998244353;
			}
			b[m]++;
			if(b[m]>n)
			{
				b[m]--;
				if(fun(m))
				{
					b[1]++;
					for(int j=2;j<=m;j++)b[j]=b[j-1]+1;
				}
				else
				{
					b[m]++;
					for(int j=m;j>=0;j--)
					{
						if(b[j]>n)
						{
							b[j-1]++;
							b[j]=b[j-1]+1;
							if(b[j-1]==n)
							{
								b[j-2]++;
								b[j-1]=b[j-2]+1;
								b[j]=b[j-1]+1;
							}
						}
					}
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(b[j]>n)f=0;
			}
		}
	}
	cout<<sum;
	goodbye
}
//花了好久，只是过了两个样例，就这样吧，我也写不出来了 
