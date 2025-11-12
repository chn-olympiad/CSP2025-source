#include<bits/stdc++.h>
using namespace std;
int fa[323232],n,m,k,c[323232],q[15][301011],lj;
bool gz[12];
struct Node{
	int u,v,w;
}a[323232];
inline bool cmp(Node a,Node b){
	return a.w<b.w;
}
inline int getfa(int x){
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
inline void merge(int a,int b){
	fa[getfa(a)]=getfa(b);
} 
inline void kruskal(){
	sort(a+1,a+n+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(getfa(a[i].u)==getfa(a[i].v)) continue;
		if(k){
			for(int y=1;y<=lj;y++){
				if(gz[y]) continue;
				int g=c[y];
				if(a[i].w>g) gz[y]=1,k--;
			}
		}
		merge(a[i].u,a[i].v);
		ans+=a[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k,lj=k;
	for(int i=1;i<=n;i++) cin>>a[i].u>>a[i].v>>a[i].w,fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>q[i][j];
	}
	kruskal();
	return 0;
}
