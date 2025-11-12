#include <bits/stdc++.h>
using namespace std;
int n,k,ss,s;
int arr[50001];
int arr1[50001];
int a[5001][5001];//ll
int b[5001][5001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		s=arr[i];
		if(s==k)
		{
			arr1[i]=1;
		}
		else
		{
			for(int j=i+1;j<=n;j++)
			{
				s=s^arr[j];
				if(s==k)
				{
					arr1[i]=j-i+1;
					i=j+1;
					break;
				}
			}
		}
	}
	

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j-arr1[i]>=a[i-1][j])
			{
				a[i][j]=max(a[i][j-1],a[i-1][j]+arr1[i]);
				if(a[i][j]!=a[i-1][j])
				{
					b[i][j]=b[i-1][j]+1;
				}
					
				else
				{
					b[i][j]=b[i-1][j];
				}
					
			}
			else
			{
				a[i][j]=a[i-1][j];
				b[i][j]=b[i-1][j];
			}
		}
	}

	cout<<b[n][n]; 

	
	return 0;
}

