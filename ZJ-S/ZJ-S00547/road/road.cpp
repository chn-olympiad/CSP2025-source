#include<bits/stdc++.h>
using namespace std;
const int slen=1e7+10,slena=1e4+10;
struct info{
  int u,v,bh=0,xz=0;
  long long w;
};
info e[slen];
int fa[slena];
int txz[11];
long long bu[11][slena],ans;
bool cmp(info x,info y)
{
  return x.w<y.w;
}
int getroot(int x)
{
  if(x!=fa[x]) fa[x]=getroot(fa[x]);
  return fa[x];
}
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int n,m,k;
  cin>>n>>m>>k;
  int num=m;
  for(int i=1;i<=m;i++)
  {
  	int u,v,w;
  	cin>>u>>v>>w;
  	e[i].u=u;e[i].v=v;e[i].w=w;
  }
  for(int i=1;i<=k;i++)
  {
  	
  	cin>>bu[i][0];
  	for(int j=1;j<=n;j++)
  	  cin>>bu[i][j];
  	for(int j=1;j<n;j++)
  	{
  	  for(int k=j+1;k<=n;k++) {e[++num].u=j;e[num].v=k;e[num].w=bu[i][j]+bu[i][k]+bu[i][0];e[num].bh=i;}
	}
  }
  for(int i=1;i<=n;i++) fa[i]=i;
  sort(e+1,e+num+1,cmp);
  for(int i=1;i<=num;i++)
  {
  	int tx=getroot(e[i].u),ty=getroot(e[i].v);
  	if(tx!=ty)
  	{
  	  fa[tx]=ty;
  	  e[i].xz=1;
  	  ans+=e[i].w;
	}
  }
  for(int i=1;i<=num;i++)
  	if(e[i].xz!=0) txz[e[i].bh]++;
  for(int i=1;i<=10;i++)
  	if(txz[i]>1) ans=ans-bu[i][0]*(txz[i]-1);
  cout<<ans;
  return 0;
}