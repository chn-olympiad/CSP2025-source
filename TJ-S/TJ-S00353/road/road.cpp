#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);  
	freopen("road.out","w",stdout);
//=====================================
	cin>>n>>m>>k;
	int a[1005][3];
	int b[1005][n+1];
	int f=0;
	int mymin1=INT_MAX;
	int minid1=0;
	int mymin2=INT_MAX;
	int minid2=0;
	int mymin3=INT_MAX;
	int minid3=0;
	int mymin4=INT_MAX;
	int minid4=0;
	int mymin5=INT_MAX;
	int minid5=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][2]<mymin1)
		{
			mymin1=a[i][2];
			minid1=i;
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i][2]<mymin2 && a[i][2]!=a[minid1][2])
		{
			mymin2=a[i][2];
			minid2=i;
		}
	}
	for(int i=0;i<k;i++)
	{
		if(b[i][0]<mymin3)
		{
			mymin3=a[i][0];
			minid3=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[minid3][i]>mymin4)
		{
			mymin4=a[minid3][i];
			minid4=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[minid3][i]>mymin5 && b[minid3][i]!=b[minid3][minid4])
		{
			mymin5=a[minid3][i];
			minid5=i;
		}
	}
	cout<<mymin1+mymin2+mymin4+mymin5;
	return 0;
}
