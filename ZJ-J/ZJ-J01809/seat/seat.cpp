#include<bits/stdc++.h>
using namespace std;
int n,m,ansx,ansy;
struct node
{
	int a,id;
}c[105];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
void dfs(int u,int x,int y)
{
	if(c[u].id==1)	
	{
		ansx=x,ansy=y;
		return ;
	}
	int ny=y;
	if(x&1)	ny++;
	else	ny--;
	if(ny==0)	dfs(u+1,x+1,y);
	else if(ny>n)	dfs(u+1,x+1,y);
	else	dfs(u+1,x,ny);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)	cin>>c[i].a,c[i].id=i;
	sort(c+1,c+1+k,cmp);
	dfs(1,1,1);
	cout<<ansx<<' '<<ansy;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
