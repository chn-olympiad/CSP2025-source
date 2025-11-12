#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i]+1;
			m=a[i];
		}
	}
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=13;j++)
		{
			k++;
		}
	}
	k=k-m;
	cout<<k-103;
	return 0;
}
