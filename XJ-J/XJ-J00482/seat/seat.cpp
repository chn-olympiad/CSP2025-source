#include<bits/stdc++.h>
using namespace std;
int a[15][15],f[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k,n,m,sum;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>f[i];
	}	sum=f[1];
	sort(f+1,f+n*m+1,cmp);

	int x=1,cnt=0;

		for(j=1;j<=m;j++)
		{
			if(j%2==0)
			{
				for(x=n;x>=1;x--) a[x][j]=f[++cnt];
			}
			else
			{
				for(x=1;x<=n;x++) a[x][j]=f[++cnt];
			}
		}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==sum)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}




/*
100  56  39  21
89   46  35  15
65   44  26  12
*/
