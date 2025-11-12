#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int from,to;
	long long v;
	//Node(int a,int b,long long c){from=a;to=b;v=c;}
}l[3000009],newl[3000009];
int root[200009];
long long w[109];
long long v[19][1000009];
int used[29];
int cnt;
long long cost=INT_MAX;
int n,m,k;
int cmp(Node a,Node b)
{
	return a.v<b.v;
}
int find(int a)
{
	if(root[a]==a)
		return a;
	return find(root[a]);
}
void kruskal()
{
	long long newcost=0;
	int gs=m;
	for(int i=1;i<=m;i++)
		newl[i].from=l[i].from,newl[i].to=l[i].to,newl[i].v=l[i].v;
	for(int i=1;i<=k;i++)
		if(used[i]==1)
		{
			for(int j=1;j<=n;j++)
			{
				newl[++gs].from=n+i,newl[gs].to=j,newl[gs].v=v[i][j];
				//cout<<n+i<<" "<<j<<" "<<v[i][j]<<endl;
			}
			newcost+=w[i];
		}
	for(int i=1;i<=n+k;i++)
		root[i]=i;
	sort(newl+1,newl+gs+1,cmp);
	for(int i=1;i<=gs;i++)
	{
		int x=newl[i].from,y=newl[i].to;
		//cout<<x<<" "<<y<<endl;
		int fx=find(x),fy=find(y);
		if(fx==fy)
			continue;
		else
		{
			root[fx]=root[y],newcost+=newl[i].v;
		}
	}
	//\cout<<newcost<<endl;
	cost=min(cost,newcost);
}
void dfs(int a)
{
	if(a==k+1)
	{
		kruskal();
		return ;
	}
	used[a]=0;
	dfs(a+1);
	used[a]=1;
	dfs(a+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		long long c;
		cin>>a>>b>>c;
		l[i].from=a,l[i].to=b,l[i].v=c;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		for(int j=1;j<=n;j++)
		{
			long long va;
			cin>>va;
			v[i][j]=va;
		}
	}
	dfs(1);
	cout<<cost<<endl;
	return 0;
}
