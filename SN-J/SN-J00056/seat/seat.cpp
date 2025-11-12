#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100000006],r;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(i-1)*m+j];
			if(i==1 && j==1)
			{
				r=a[(i-1)*m+j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>0;j--)
			{
				if(a[(i-1)*m+j]>a[(i-1)*m+j-1])
				{
					int t=a[(i-1)*m+j-1];
					a[(i-1)*m+j-1]=a[(i-1)*m+j];
					a[(i-1)*m+j]=t;
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(a[(i-1)*m+j]<a[(i-1)*m+j+1])
				{
					int t=a[(i-1)*m+j+1];
					a[(i-1)*m+j+1]=a[(i-1)*m+j];
					a[(i-1)*m+j]=t;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[(i-1)*m+j]==r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

