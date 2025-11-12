#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
const int M = 1e6+5;

int n,m,k,fa[N],cnt,arr;

struct Edge{
	int u,v,w;
}T[M];

int iFind(int x){
	return ((fa[x]==x)?(fa[x]):(fa[x]=iFind(fa[x])));
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n+k;i++) fa[i] = i;
	for(int i=1;i<=m;i++){
		cin >> T[i].u >> T[i].v >> T[i].w;
	}
	sort(T+1,T+1+m,[](Edge a,Edge b){
		return a.w < b.w;
	});
	for(int i=1;i<=m;i++){
		int u = T[i].u,v = T[i].v,w = T[i].w;
		int x = iFind(u),y = iFind(v);
		if(x==y) continue;
		fa[x] = y;
		arr += w;
	}
	cout << arr << endl;
	return 0;
}
