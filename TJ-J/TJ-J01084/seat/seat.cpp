#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int a[405],b[500][500],c[500][500];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	const int r = a[1];
	sort(a+1,a+n*m+1);
	int sum = 1;
	for(int i = 1;i<=n;i++)
	{
		if((i-1) % 2 == 1)
		{
			for(int j = m;j>=1;j--)
			{
				b[i][j] = sum;
				sum++;
			}
		}
		else
		{
			for(int j = 1;j<=m;j++)
			{
				b[i][j] = sum;
				sum++;
			}
		}
	}
	int l = 1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(l == b[i][j])
			{
				c[i][j] = a[n*m-l+1];
				l++;
			}
		} 
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(r == c[i][j]) 
			{
				cout<<i<<" "<<j;
				return 0;
			}
		} 
	}
	return 0;
}
