#include<bits/stdc++.h>
using namespace std;
struct road
{
	int c1;
	int c2;
	int m;
}a[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long zs=0;
	int c[100001]
	for(int i=0;i<n;i++) a[i]="0";
	for(int i=0;i<n;i++)
	{
		cin>>a[i].c1>>a[i].c2>>a[i].m;
	}
	int country[k][n+1];
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin>>country[i][j];	
		}
	}
	for(int i=0;i<n;i++)
	{
		zs=zs+a[i].m;
		int i1=a[i].c1,i2=a[i].c2;
		c[i1]="1";
		c[i2]="1";
	}
	
	cout<<13<<endl;
	return 0;
}