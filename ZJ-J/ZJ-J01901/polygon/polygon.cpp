#include<bits/stdc++.h>
using namespace std;
int cnt[5001];
int b[5001],d=0;
int n,cnt1;
int hs(int x)
{
	int c1=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]=x)
		{
			c1=i;
			break;
		}
	}
	for(int i=1;i<c1;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i+j==x)
			{
				return i,j;
			}
		}
	}
	return x;
}
int main()
{
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=5000;i++)
	{
		if(cnt[a[i]]!=0)
		{
			for(int j=1;j<=cnt[a[i]];j++)
			{
				d++;
				b[d]=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int c=2*b[i];
		for(int j=1;j<i;j++)
		{
			for(int z=1;z<j;z++)
			{
				if(b[i]+b[j]+b[z]>c)
				{
					cnt1++;
				}	
			}	
		}
	}
	cout<<cnt1;
	return 0;
}
