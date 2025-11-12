#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,k,f[100010],tmp;
long long find(long long x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
struct edge{
	long long u,v,w;
	bool operator <(edge b){
		return w<b.w;
	}
}e[10000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=10*n;i++){
		f[i]=i;
	}
	for(long long i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>tmp;
		for(long long j=1;j<=n;j++){
			cin>>e[++m].w;
			e[m].u=n+i,e[m].v=j;
		}
	}
	long long ans=0,eg=n+k-1;
	sort(e+1,e+1+m);
	for(long long i=1;i<=m;i++){
		long long x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			f[x]=y;
			eg--;
			ans+=e[i].w;
			if(eg==0) break;
		}
	}
	cout<<ans;
	return 0;
}
