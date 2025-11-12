#include<bits/stdc++.h>
using namespace std;
void files(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return;
}
const int M=1e6+5,N=1e4+5,K=15;
int n,m,k,fa[N],ans,c[K],a[K][N];
struct road{
	int u,v,w;
}r[M+K];
bool cmp(road x,road y){return x.w<y.w;}
void init(){ans=0;for(int i=1;i<=n;i++){fa[i]=i;}}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void pK(){
	sort(r+1,r+m+1,cmp);
	init();
	for(int i=1;;i++){
		int fx=find(r[i].u),fy=find(r[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=r[i].w;
	}
	cout<<ans<<'\n';
	return;
}
void pA(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				for(int l=1;l<=n;l++){
					if(l==j)continue;
					r[m+l].u=j;
					r[m+l].v=l;
					r[m+l].w=a[i][l];
				}
			}
		}
	}
	sort(r+1,r+m+k+1,cmp);
	init();
	for(int i=1;;i++){
		int fx=find(r[i].u),fy=find(r[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=r[i].w;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	files();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>r[i].u>>r[i].v>>r[i].w;
	bool pendA=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)pendA=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		pK();return 0;
	}
	if(pendA){
		pA();return 0;
	}
}
