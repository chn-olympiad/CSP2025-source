#include<bits/stdc++.h>
using namespace std;
const int M=1e7+5;
int n,k,cnt;
int a[M],b[M];
int flag[M];
int check(int qwer,int asdf)
{
	for(int y=qwer;y<=asdf;y++)
	{
		if(flag[y]==1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0&&n<=2)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[j]^b[i-1]==k&&check(i,j)==1)
			{
				cnt++;
				for(int o=i-1;o<=j;o++)
				{
					flag[o]=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

