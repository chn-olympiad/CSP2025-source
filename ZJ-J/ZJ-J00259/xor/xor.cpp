#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool yang1=true,yang2=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)	yang1=false;
		if(a[i]>1)	yang2=false;
//		int num=0,sum=0;
//		while(n/=2)
//		{
//			sum++;	
//		}                       
	}
	if(k==0&&yang1)	cout<<0;
	else if(k<=1&&yang2)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				cnt++;
			}
		}
		cout<<cnt;
	}
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i;j<=n;j++)
//			{
//				for(int k=i;k<=j;k++)
//				{
//					int dp[500005]={};
//					dp[i]=a[i];
//					int p=dp[k],q=a[k];
//					while(p/=10&&q/=10)
//					{
//						
//					}
//				}
//			}
//		}
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 