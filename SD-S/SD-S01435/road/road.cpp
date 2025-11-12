#include<bits/stdc++.h>
using namespace std;
int n,m,p,x,y,z,f[1024][10001],g[10001][10001],b[11][10001];
bool Q,d[10001];
vector<pair<int,int>> a[10001];
struct S{
	int x,y,z;
	bool operator < (const S &A) const{
		return z<A.z;
	}
};
void solve2(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=p;k++)
	g[i][j]=min(g[i][j],b[k][i]+b[k][j]);
	vector<S> c;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c.push_back({x,y,z});
	sort(c.begin(),c.end());
	long long o=0;
	int t=0;
	for(auto i:c)
	if(!d[i.x]||!d[i.y]){
		d[i.x]=d[i.y]=1;
		o+=i.z;
		if(++t==n)
		break;
	}
	printf("%lld",o);
}
S c[1000001];
void solve1(){
	sort(c+1,c+m+1);
	long long o=0;
	int t=0;
	for(auto i:c)
	if(!d[i.x]||!d[i.y]){
		d[i.x]=d[i.y]=1;
		o+=i.z;
		if(++t==n)
		break;
	}
	printf("%lld",o);	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	memset(g,127,sizeof(g));
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
		c[i]={x,y,z};
		g[x][y]=g[y][x]=min(g[x][y],z);
	}
	for(int i=1;i<=p;i++){
		for(int j=0;j<=n;j++)
		scanf("%d",&b[i][j]);
		if(b[i][0])
		Q=1;
	}
	if(!p){
		solve1();
		return 0;
	}
	if(!Q){
		solve2();
		return 0;
	}
	return 0;
}
