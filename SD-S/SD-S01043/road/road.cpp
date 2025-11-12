#include <bits/stdc++.h>
using namespace std;
const int N=1010,K=11,M=1e6+10;
int n,m,k,u,v,w,c[N],a[K][N],e2[N][N],f[N],cnt2;
long long ans;
struct node{
	int u,v,w;
}e[M];
bool cmp(node o,node p){
	return o.w<p.w;
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void Kruscal(){
	stable_sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		ans+=1ll*e[i].w;
		if(++cnt==n-1){
			cout<<ans;
			return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
//	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
//		return 0;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			e2[i][j]=2e9+10;
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cin>>u>>v>>w;
//		e2[min(u,v)][max(u,v)]=min(w,e2[min(u,v)][max(u,v)]);
//	}
//	bool fl=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
//		if(c[i]!=0) fl=false;
		for(int j=1;j<=n;j++) cin>>a[i][j]; 
	}
//	if(fl){
//		m=0;
//		for(int i=1;i<=n;i++) e2[i][i]=0;
//		for(int i=1;i<=k;i++){
//			for(int j=1;j<=n;j++){
//				for(int sgf=1;sgf<j;sgf++){
//					e2[sgf][j]=min(a[i][j]+a[i][sgf],e2[sgf][j]);
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<i;j++){
//				if(e2[j][i]!=(2e9+10)){
//					e[++m]={j,i,e2[j][i]};
//				}
//			}
//		}
//		Kruscal();
//		return 0;
//	}
	Kruscal();
	return 0;
}
