#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5; 
int n,m,k;
struct Edge{
	int x;
	int y;
	int w;
	bool operator < (Edge t) const{
		return w<t.w;
	}
}e[M],tmp[M<<1];
int fa[N<<1];
int c[15];
int w[15][N];
bool vis[N];
void init_set(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
void init_set2(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
} 
int getfa(int x){
	if(x!=fa[x]){
		fa[x]=getfa(fa[x]);
	}
	return fa[x];
}
long long kruskal(){
	sort(e+1,e+1+m);
	init_set();
	long long ans=0;
	for(int i=1;i<=m;i++){
		int fax=getfa(e[i].x),fay=getfa(e[i].y);
		if(fax==fay) continue;
		fa[fax]=fay;
		ans+=e[i].w;
	}
	return ans;
}
int cnt=0;
int addedges(){
//	for(int i=1;i<=k;i++) cout << vis[i] << ' ';
//	cout << endl;
	cnt=0;
	for(int i=1;i<=m;i++){
		tmp[i]=e[i];
	}
	int now=m;
	for(int i=1;i<=k;i++){
		if(!vis[i]) continue;
		for(int j=1;j<=n;j++){
			tmp[++now]={n+i,j,w[i][j]};
		}
		cnt+=c[i];
	} 
//	cout << now << endl;
//	for(int i=m+1;i<=now;i++){
//		cout << tmp[i].x << ' ' << tmp[i].y << ' ' << tmp[i].w << endl;
//	}
	return now;
}
long long kruskal2(int mm){
	sort(tmp+1,tmp+1+mm);
//	for(int i=1;i<=mm;i++){
//		cout << tmp[i].x << ' ' << tmp[i].y << ' ' << tmp[i].w << endl; 
//	} 
	init_set2();
	long long ans=cnt;
	for(int i=1;i<=mm;i++){
		int fax=getfa(tmp[i].x),fay=getfa(tmp[i].y);
		if(fax==fay) continue;
		ans+=tmp[i].w;
		fa[fax]=fay;
	}
//	cout << ans << endl;
	return ans;
} 
long long dfs(int x){
	if(x>k){
		int nm=addedges();
		return kruskal2(nm);
	}
	long long ret=1e18;
	ret=min(ret,dfs(x+1));
	vis[x]=1;
	ret=min(ret,dfs(x+1));
	vis[x]=0;
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[i]={x,y,w};
	}
	if(k==0){
		long long ans=kruskal();
		printf("%lld",ans);
	}else{
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&w[i][j]);
			}
		} 
		long long ans=dfs(1);
		printf("%lld",ans); 
	}
	return 0; 
} 
