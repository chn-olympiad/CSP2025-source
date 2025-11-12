#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{
			for(int l=k+1;l<=n;l++)
			{
				if(k+l>j&&j+l>k&&j+k>l)
				{
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
