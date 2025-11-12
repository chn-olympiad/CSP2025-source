#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
};
vector<Node> a[1000010];
int Min=INT_MAX,n,m,k,xx,yy,zz;
bool used[1010];
void dfs(int x,int step,int sum)
{
	if(step==n)
	{
		Min=min(Min,sum);
		return ;
	}
	if(sum>Min) return ;
	for(int i=0;i<a[x].size();i++)
	if(used[a[x][i].x]==0)
	{
		used[a[x][i].x]=1;
		dfs(a[x][i].x,step+1,sum+a[x][i].y);
		used[a[x][i].x]=0;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>xx>>yy>>zz;
		Node t;
		t.x=yy,t.y=zz;
		a[xx].push_back(t);
		t.x=xx;
		a[yy].push_back(t);
	}
	for(int i=1;i<=k;i++)
	  for(int j=0;j<=m;j++)
	    cin>>xx;
	for(int i=1;i<=n;i++)
	{
		used[i]=1;
		dfs(i,1,0);
		used[i]=0;
	}
	cout<<Min;
}
