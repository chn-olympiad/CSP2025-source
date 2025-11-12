#include<iostream>
#include<algorithm>
using namespace std;
int cj[105];
int u[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=n*m;
	for(int i=0;i<f;i++)
	{
		cin>>cj[i];
	}
	int xr=cj[0];
	sort(cj,cj+f,cmp);
	int sta=0;
	for(int i=1;i<=m;i++)
	{
		if(m%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				u[i][j]=cj[sta];
				sta++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				u[i][j]=cj[sta];
				sta++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(u[i][j]==xr)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
