#include<bits/stdc++.h>
using namespace std;
int a[5005],sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxi;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	sort(a+1,a+n+1);
//	cout<<(a[n]+4)%998224353;//别管我，我就是个骗分的
//以下是试着做的代码，完全不会QAQ 
	for(int i=1;i<=n;i++)
	{
		int len=a[i]+a[i+1]+a[i+2];
		for(int j=i+3;j<=n;j++)
		{
			len+=a[j];//木棍长的总和 
			maxi=0;
			for(int k=i;k<=j;k++)//找最长的木棍 
			{
				maxi=max(a[k],maxi);
			}
			if(len>maxi*2)
			{
				sum++;
				continue;
			}
		}
	}
	cout<<sum%998224353;
	return 0;
}//0分
