#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mid (l+r)/2
const int N=1e5+10;
ll n,m,k,s=INT_MAX;
struct node{
	ll u,h;
	bool operator<(const node &x){
		return h>x.h;
	}
};
vector<node>g[N];
ll vis[N],dis[N];
ll no[N],non;
void add(int x,int y,int k){
	g[x].push_back((node){y,k});
}
void dij(int x){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[x]=0;
    no[x]=1;non++;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		if(vis[v])continue;
		vis[v]=1;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i].u,h=g[v][i].h+dis[v];
			if(dis[u]>h){
				dis[u]=h;
				q.push(u);
			}
		}
	}
}
vector<int>p;
int gl(int j,int x){
	if(j==x)return x;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i].u;
	    return gl(j,u);
	}
}
void gt(int x){
	p[x]=1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i].u,h=g[x][i].h;
	    p[u]=1;
	    s+=dis[u];
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)s+=dis[gl(i,x)]-dis[i];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;

for(int i=1;i<=m;i++)
{
	int a,b,c;
	cin>>a>>b>>c;
	add(a,b,c),add(b,a,c);
	add(a+n+1,b+n+1,c),add(b+n+1,a+n+1,c);
}
for(int i=1;i<=k;i++){
	int x;
	cin>>x;
	int t[n];
	for(int j=1;j<=n;j++)
	  cin>>t[j];
	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=m;k++){
			add(j,k,t[j]+t[k]+x),add(k,j,t[j]+t[k]+x);
		}
	}
}	
dij(1);
gt(1);
cout<<s<<endl;
 } 
