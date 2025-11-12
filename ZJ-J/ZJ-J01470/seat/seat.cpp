#include<bits/stdc++.h>
using namespace std;
int bj(int a,int b)
{
	if(a>=b)
	return 1;
	else
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cj=a[1];
	sort(a+1,a+n*m+1,bj);
	int zw[11][11];
	int num=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2==1)
			zw[j][i]=a[num];
			else
			zw[n-j+1][i]=a[num];
			num++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(cj==zw[i][j])
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
 	return 0;
}
