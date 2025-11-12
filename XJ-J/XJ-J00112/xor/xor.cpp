#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0,sum=0,x=0;
	int i=1,j=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			x=a[i];
			for(int l=i+1;l<=j;l++)
			{
				x^=a[l];
			}
			if(x==k)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
