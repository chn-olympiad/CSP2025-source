#include <bits/stdc++.h>
using namespace std;
int a[105],vis[15][15],r,l,h,idx=1,n,m;
int dx[]={-1,1,0};
int dy[]={0,0,1};
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y)
{
	if(a[idx]==r)
	{
		l=y,h=x;
		return ;
	}
	for(int i=0;i<3;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0)
		{
			vis[nx][ny]=1;
			idx++;
			dfs(nx,ny);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	vis[1][1]=1;
	dfs(1,1);
	printf("%d %d",l,h);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
