#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
long long  a[100000005];
int sum;
 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(i+j+k>2*max(i,max(j,k)))
				{
					sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
