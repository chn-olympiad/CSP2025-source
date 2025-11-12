#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e6+5;
struct edge{
	int u,v,w;
}a[N];
int tot,fa[N],n,m,k;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void add(int x,int y,int z){
	a[++tot].u=x;
	a[tot].v=y;
	a[tot].w=z;
}
int fd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
bool merge(edge x){
	int xx=fd(x.u),yy=fd(x.v);
	if(xx!=yy){
		fa[xx]=yy;
		return 1;
	}
	return 0;
}
int kruskal(){
	for(int i=0;i<=n;i++) fa[i]=i;
	sort(a+1,a+tot+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=tot;i++)
		if(merge(a[i])){
			cnt++;ans+=a[i].w;
			if(cnt==n-1) break;
		}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		add(ui,vi,wi);
	}
	for(int i=1;i<=k;i++){
		int ci;cin>>ci;
		for(int j=1;j<=n;j++){
			int wi;cin>>wi;
			add(n+i,j,wi);
		}
	}
	cout<<kruskal();
	return 0;
}