#include<bits/stdc++.h>
using namespace std;
struct EDGE{
	long long v;
	long long w;
};
long long n,m,k;
EDGE G[10014][10014];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		EDGE d1,d2;
		d1.v=v;
		d2.v=u;
		d1.w=d2.w=w;
		G[u][++G[u][0].v]=d1;
		G[v][++G[v][0].v]=d2;
	}
	for(long long i=1;i<=n;i++){
		
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
