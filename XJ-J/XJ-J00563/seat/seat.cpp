#include<bits/stdc++.h>
using namespace std;
int dx[8]={+1,-1,0,0,-1,-1,+1,+1};
int dy[8]={0,0,-1,+1,-1,+1,-1,+1};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m,i,j,b[15][15];
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i];
		}
	}
	int l=a[1];
	int k=n*m;
	sort(a+1,a+k+1,cmp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==n&&a[j]==m) b[i][j]=b[n][m];
		}
		cout<<i<<" ";
	}
	return 0;
}
