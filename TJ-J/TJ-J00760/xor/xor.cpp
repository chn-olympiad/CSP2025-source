#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
//int f[200050][200050]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k=0,n=0,sum=0;
	cin>>n>>k;
	vector<long long> v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i]==1)
			{
				sum++;
			}	
		}	
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				sum++;
			}	
			if(v[i+1]==v[i]==v[i+2] && v[i+3]!=v[i])
			{
				sum+=1;
				i+=2;
			}
			else if(v[i+1]==v[i]==v[i+2]==v[i+3])
			{
				sum+=2;
				i+=3;
			}
			else if(v[i]==v[i+1])
			{
				sum+=1;
				i+=1;
			}
		}	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x=v[i]*v[j];
				if(x==k)
				{
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
