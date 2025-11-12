#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum,b[15][1000005],c[1000005];
struct node{
	int u,v,w;
}a[1000005];
bool d[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
bool cmp1(int x,int y){
	return x<y;
}
int find(int x){
	int y=x;
	while(c[y]!=y)
		y=c[y];
	c[x]=y;
	return c[x];
}
void dfs(int x,int y,long long s){
	if(x==n){
		if(sum==-1) sum=s;
		else sum=min(sum,s);
		return;
	}
	if(s>sum&&sum!=-1) return;
	if(find(a[y].u)!=find(a[y].v)){
		int t=c[a[y].v];
		c[a[y].v]=a[y].u;
		dfs(x+1,y+1,s+a[y].w);
		c[a[y].v]=t;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int jj=j+1;jj<=n;jj++){
				if(d[i]==1)
					dfs(x+1,y,s+b[i][j]+b[i][jj]);
				else{
					d[i]=1;
					dfs(x+1,y,s+b[i][0]+b[i][j]+b[i][jj]);
					d[i]=0;
				}
			}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		c[i]=i;
	memset(d,0,sizeof(d));
	sum=-1;
	dfs(0,0,0);
	cout<<sum;
}
