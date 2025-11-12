#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a[105]={};
	int zw[16][16]={};
	int cj=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int i=1;i<=n;i+=2)
	{
		for(int j=1;j<=m;j++)
		{
			zw[j][i]=a[cnt];
			cnt--;
		}
		for(int j=m;j>=1;j--)
		{
			zw[j][i+1]=a[cnt];
			cnt--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(zw[i][j]==cj)
			{
				cout<<j<<" "<<i;
			}
		}	
	}
	return 0;
 } 
