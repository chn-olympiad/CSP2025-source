#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}a[10010];
int fa[10010],n,k,m,u,v,w,c[20],p[20][10010],lj[1010][1010],tot;
int fi(int d){
	if(fa[d]==d) return d;
	else return fa[d]=fi(fa[d]);
}
int mobify(int x,int y){
	x=fi(x);
	y=fi(y);
	if(x>y) swap(x,y);
	if(x!=y) fa[y]=x;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int klske(){
	int tmp=0,ans=0;
	sort(a,a+tot,cmp);
	for(int i=0;i<tot;i++){
		if(fi(a[i].u)!=fi(a[i].v)){
			mobify(a[i].u,a[i].v);
			tmp++;
			ans+=a[i].w;
			if(tmp==n-1) break;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(lj,0x3f,sizeof(lj));
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k!=0){
		for(int i=0;i<m;i++){
			cin>>u>>v>>w;
			lj[u][v]=min(lj[u][v],w);
			lj[v][u]=min(lj[v][u],w);
		}
		for(int i=0;i<k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>p[i][j];
				for(int g=1;g<j;g++){
					lj[j][g]=min(lj[j][g],c[i]+p[i][j]+p[i][g]);
					lj[g][j]=min(lj[g][j],c[i]+p[i][j]+p[i][g]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){
				a[tot].u=i;
				a[tot].v=j;
				a[tot++].w=lj[i][j];
			}
	}else{
		for(int i=0;i<m;i++)
			cin>>a[i].u>>a[i].v>>a[i].w;
		tot=m;
	}
	cout<<klske();
	return 0;
}
