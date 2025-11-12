#include<bits/stdc++.h>
using namespace std;
const int slen=1e6+10,slen1=1e4+10;
struct info1{
  int u,v,w;
};
int n,m,k;
int e[slen1][slen1],fa[slen],ans=0;
priority_queue<info1> pq;
bool operator<(info1 a,info1 b)
{return a.w>b.w;}
int fy(int x)
{
  if(fa[x]==x)return x;
  return fa[x]=fy(fa[x]);
}
int main()
{
  freopen("rode.in","r",stdin);
  freopen("rode.out","w",stdout);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=m;i++)
  {
  	int u,v,w;cin>>u>>v>>w;
  	e[u][v]=w;
  	e[v][u]=w;
  }
  for(int i=1;i<=k;i++)
  {
  	int c,xw[slen];cin>>c;
  	memset(xw,0,sizeof(xw));
  	for(int j=1;j<=n;j++)
  	  cin>>xw[j];
  	for(int j=1;j<=n;j++)
  	{
  	  for(int k1=1;k1<=n;k1++)
  	  {
  	  	if(xw[j]+xw[k1]+c<e[j][k1]) 
		{  pq.push({j,k1,xw[j]+xw[k1]+c});
		   e[j][k1]=e[k1][j]=xw[j]+xw[k1]+c;
		}
		else  pq.push({k1,j,e[k1][j]});
	  }
	}
  }
  while(!pq.empty())
  {
  	info1 to=pq.top();
  	pq.pop();
  	int u=to.u,v=to.v,w=to.w;
  	if(fy(u)!=fy(v))
	{
	  fa[fy(u)]=fy(v);
	  ans+=w;
    }
  }
  cout<<ans;
  return 0;
}