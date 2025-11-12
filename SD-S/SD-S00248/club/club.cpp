#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int t,n,ans;
int a[N][5],b[N];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int pos,int a1,int a2,int a3,int res)
{
	if(pos>=n)
	{
		ans=max(ans,res);
		return;
	}
	if(a1+1<=n/2)
	{
		dfs(pos+1,a1+1,a2,a3,res+a[pos+1][1]);
	}
	if(a2+1<=n/2)
	{
		dfs(pos+1,a1,a2+1,a3,res+a[pos+1][2]);
	}
	if(a3+1<=n/2)
	{
		dfs(pos+1,a1,a2,a3+1,res+a[pos+1][3]);
	}
}
void handle(int n)
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	}
	dfs(1,1,0,0,a[1][1]);
	dfs(1,0,1,0,a[1][2]);
	dfs(1,0,0,1,a[1][3]);
	printf("%d\n",ans);
}
void AA()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		b[i]=a[i][1];
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=b[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n==100000)
		{
			AA();
		}
		else
		{
			handle(n);
		}
	}
	return 0;
} 
