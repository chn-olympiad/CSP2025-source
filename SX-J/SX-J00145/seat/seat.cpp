#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b,n,m,c[25][25],k=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	a[0]=b;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
  			{
				c[i][j]=a[n*m-k-1];
				k++;
			}
		}else{
			for(int j=0;j<m;j++)
  			{
				c[i][m-j]=a[n*m-k-1];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==b)
			{
				cout<<i<<' '<<j;
   			}
		}
	}
	return 0;
}