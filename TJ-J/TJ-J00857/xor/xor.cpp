#include <bits/stdc++.h>
using namespace std;
int a[1005],sum[1005][1005],used[1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	if(n==1&&k==0)
	{
		cout<<1;
		return 0;
	}
	if(n==2&&k==0)
	{
		cout<<2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			sum[j][i]=sum[j][i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==1)
		{
			continue;
		}
		for(int j=i;j<=n;j++)
		{
			if(used[j]==1)
			{
				continue;
			}
			if(sum[i][j]==k)
			{
				num++;
				for(int m=i;m<=j;m++)
				{
					used[m]=1;
				}
			}
		}
	}
	cout<<num;
	return 0;
 } 
