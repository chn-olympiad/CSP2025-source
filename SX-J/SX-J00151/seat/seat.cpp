#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N],sq[15][15];
int n,m,r,d,x=1,y=1,num=1;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,1};
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		r=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(r==a[i])
		{
			r=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
				sq[x][y]=num;
				num++;
				int fx=x+dx[d];
				int fy=y+dy[d];
				if(fx>n||fy>n||fx<1||fy<1||sq[fx][fy]!=0||d==1||d==3)
				{
					d=(d+1)%4;
				}

				x+=dx[d];
				y+=dy[d];

		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r==sq[i][j])
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}