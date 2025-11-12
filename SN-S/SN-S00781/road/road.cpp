//SN-S00781 Âíè÷Ğù 
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1010],c[20][1010],d[20];
struct node{
	int u,v,w;
}g[10000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x];
}
void merge(int x,int y){
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	int check=0;
	for(int i=1;i<=k;i++){
		cin >> d[i];
		if(d[i]!=0) check=1;
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
		}
	}
	
	//ÌØÊâĞÔA
	int inv=m;
	if(check==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int f=j;f<=n;f++){
					if(j==f) continue;
					inv++;
					g[inv].u=j,g[inv].v=f,g[inv].w=c[i][j]+c[i][f];
				}
			}
		}
	}
	
	sort(g+1,g+inv+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=inv;i++){
		if(get(g[i].u)!=get(g[i].v)){
			merge(g[i].u,g[i].v);
			ans+=g[i].w;
		}
	}
	cout << ans;
	return 0;
}
