#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int tmp[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>tmp[(i-1)*n+j];
		}
	}int ba=tmp[1];
	sort(tmp+1,tmp+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=tmp[(i-1)*n+j];
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		bool tex=i%2;
		for(int r=1;r<=m;r++)
		{
			for(int z=r;z<=m;z++)
			{
				if(tex==1)
				{
					if(a[i][r]<a[i][z])
					{
						swap(a[i][r],a[i][z]);
					}
				}
				else
				{
					if(a[i][r]>a[i][z])
					{
						swap(a[i][r],a[i][z]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==ba)
			{
				cout<<i<<' '<<j;
			}
		}
	}
	ios::sync_with_stdio(0);
	
	return 0;
}
