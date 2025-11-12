#include<bits/stdc++.h>
using namespace std;
int n,m,K;
#define ll long long
const int MM=1e6+5,NN=1e4+5,KK=15;
struct edge{
	int u,v,w;
	bool operator<(const edge&X)const{
		return w<X.w;
	}
}e[MM],usd[NN],vil[15][NN],tmp[NN*11],lst[NN*11];
int tot,fa[NN+KK];
int Find(int x){
	if(x==fa[x])return x;
	fa[x]=Find(fa[x]);
	return fa[x];
}
int tot_lst,c[KK],a[KK][NN],tot_tmp;
void Merge(edge*x,int lx,edge*y,int ly){
	tot_tmp=0;
	int px=1,py=1;
	while(px<=lx&&py<=ly){
		if(x[px]<y[py]){
			tmp[++tot_tmp]=x[px];
			px++;
		}else{
			tmp[++tot_tmp]=y[py]; 
			py++;
		}
	}
	while(px<=lx){
		tmp[++tot_tmp]=x[px];
		px++;
	}
	while(py<=ly){
		tmp[++tot_tmp]=y[py];
		py++;
	}
}
const ll INF=1e18;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			vil[i][j]=edge{n+i,j,a[i][j]};
		}
		sort(vil[i]+1,vil[i]+n+1);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		edge E=e[i];
		int fu=Find(E.u),fv=Find(E.v);
		if(fu==fv)continue;
		usd[++tot]=E;
		fa[fu]=fv; 
	}
//	for(int i=1;i<=tot;i++)cout<<usd[i].u<<" "<<usd[i].v<<" "<<usd[i].w<<'\n';
	ll ans=INF;
	for(int i=0;i<(1<<K);i++){
		tot_lst=tot;
		for(int j=1;j<=tot;j++)lst[j]=usd[j];
		ll ret=0;
		for(int j=1;j<=K;j++){
			if((i>>(j-1))&1){
				Merge(lst,tot_lst,vil[j],n);
				tot_lst=tot_tmp;
				for(int k=1;k<=tot_lst;k++)lst[k]=tmp[k];
				ret+=c[j];
			}
		}
		for(int j=1;j<=n+K;j++)fa[j]=j;
		for(int j=1;j<=tot_lst;j++){
			edge E=lst[j];
			int fu=Find(E.u),fv=Find(E.v);
			if(fu==fv)continue;
			fa[fu]=fv;
			ret+=E.w;
		}
		ans=min(ans,ret);
	}
	cout<<ans;
	return 0;
}
