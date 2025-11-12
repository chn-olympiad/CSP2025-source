#include<bits/stdc++.h>
using namespace std;
int a[50005],n,r,l,sum1,sum2,sum3,cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1=sum1+a[i];
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(sum1>a[n]*2)
		{
			cout<<1;
			return 0;
		}
	}
	if(n<=20)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum2=a[i]+a[j];
				sum3=sum1-sum2;
				if(i==n-1)
				{
					if(j==n)
					{
						if(sum3>(a[n-2]*2)) cnt++;
					}
				}
				else{
					if(j==n)
					{
						if(sum3>(a[n-1]*2)) cnt++;
					}
					else{
						if(sum3>(a[n]*2)) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==n)
			{
				if(sum1-a[i]>a[n-1]*2)
				{
					cnt++;
				}
			}
			else{
				if(sum1-a[i]>a[n]*2)
				{
					cnt++;
				}
			}
		}
		if(sum1>a[n]*2) cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}
