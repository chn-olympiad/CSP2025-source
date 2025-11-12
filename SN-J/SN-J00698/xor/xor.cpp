#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
long long  a[1000005][2];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==k)
		{
			sum++;
			a[i][1]=1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][0]+a[j][0]==k||a[i][0]-a[j][0]==k)
			{
				if(a[i][1]==0||a[j][1]==0)
				{
					sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
