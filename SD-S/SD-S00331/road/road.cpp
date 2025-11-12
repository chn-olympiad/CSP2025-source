#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10,M=2e6+10;
int n,m,k,tot;
vector<pii>e[N];
struct edge{
	int x,y,z;
}g[M];
int w[N],fa[N];
ll ans=0;
bool cmp(edge a,edge b)
{
	return a.z<b.z;
}
int find(int k)
{
	if(fa[k]==k)  return k;
	return fa[k]=find(fa[k]);
}
void kruskal()
{
	int cnt=0;
	sort(g+1,g+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
	  int x=g[i].x,y=g[i].y,z=g[i].z,xx,yy;
	  xx=find(x),yy=find(y);
	  if(xx==yy)  continue;
	  cnt++;ans+=z;
	  e[x].push_back(make_pair(y,z));
	  e[y].push_back(make_pair(x,z));
	  fa[xx]=yy;
	  if(cnt==n-1)  break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;tot=m;
	for(int i=1;i<=m;i++)  cin>>g[i].x>>g[i].y>>g[i].z;
	for(int i=1;i<=k;i++)
	{
	  cin>>w[i];
	  for(int j=1;j<=n;j++)
	  {
	  	int h;
	  	cin>>h;
	  	g[++tot]={n+i,j,h};
	  }
	}
	n+=k;
	for(int i=1;i<=n;i++)  fa[i]=i;
	kruskal();
	for(int i=n-k+1;i<=n;i++)
	  if(e[i].size()==1)
	    ans-=e[i][0].second;
	  else
	    ans+=w[i-n+k];
	cout<<ans<<"\n";
	return 0;
}

