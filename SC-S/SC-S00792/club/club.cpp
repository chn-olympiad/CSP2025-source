#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct ll{
	int x;
	int y;
	int z;
}b[N];
int n,t,ma;
void dfs(int i,int len,int sum,int xs,int ys,int zs)
{
//	cout<<i<<' '<<
//	cout<<sum<<endl<<endl;
	if(len==0)
	{
		ma=max(ma,sum);
		return;
	}
	if(i>n)
	{
		return ;
	}
	dfs(i+1,len,sum,xs,ys,zs);
	if(xs<n/2)
	{
		dfs(i+1,len-1,sum+b[i].x,xs+1,ys,zs);
	}
	if(ys<n/2)
	{
		dfs(i+1,len-1,sum+b[i].y,xs,ys+1,zs);
	}
	if(zs<n/2)
	{
		dfs(i+1,len-1,sum+b[i].z,xs,ys,zs+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int a[3]={0,0,0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
		}
		ma=0;
		dfs(1,n,0,0,0,0);
		cout<<ma<<endl;
	}
	
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/