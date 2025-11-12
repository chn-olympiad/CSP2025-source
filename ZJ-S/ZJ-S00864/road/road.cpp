#include<bits/stdc++.h>
using namespace std;
int fa[10010],n,m,k,ans;
struct line{
	int u,v,w;
}e[1000010];
bool cmp(line x,line y){
	return x.w<y.w;
}
int f(int x){
	if(x==fa[x]) return x;
	return f(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(n==1) break;
		int u=e[i].u,v=e[i].v;
		int fu=f(u),fv=f(v);
		if(fu!=fv){
			fa[fu]=fv;
			n--;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}