#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define ll long long
const ll MAXN=10010,MAXM=15000100,INF=1e18+7;
ll n,m,k,tot;
ll ans=0,res=0;
ll ee[MAXN][MAXN];
ll num[15][MAXN],c[20];
bitset<11> lzt;
bool vis[20];
ll fa[MAXN];
struct E{
	ll fro,to,w;
	ll flag;
}e[MAXM];
void add(ll u,ll v,ll z,ll p){
	e[++tot].fro=u;
	e[tot].to=v;
	e[tot].w=z;
	e[tot].flag=p;
	return ;
}
ll Get(ll x){
	if(x==fa[x])
		return x;
	return fa[x]=Get(fa[x]);
}
bool cmp(E x,E y){
	return x.w<y.w;
}
void kruskal(){
	ll nu=0;
	for(ll i=1;i<=k;i++)
		vis[i]=0;
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	for(ll i=1;i<=tot;i++){
		ll x=Get(e[i].fro),y=Get(e[i].to);
		if(e[i].flag>0&&lzt[e[i].flag]==0)
				continue;
		if(x==y)
			continue;
		++nu;
		vis[e[i].flag]=1;
		fa[x]=y;
		res+=e[i].w;
		if(nu==n-1)
			return ;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			ee[i][j]=INF;
		}
	}
	for(ll i=1;i<=m;i++){
		ll u,v,z;
		cin>>u>>v>>z;
		if(z<ee[u][v]||z<ee[v][u]){
			add(u,v,z,0);
			ee[u][v]=min(z,ee[u][v]);
			ee[v][u]=min(z,ee[v][u]);
		}
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>num[i][j];
		}
		for(ll j=1;j<=n;j++){
			for(ll id=j+1;id<=n;id++){
				if(num[i][j]+num[i][id]<=ee[j][id]||num[i][j]+num[i][id]<=ee[id][j]){
					ee[j][id]=min(num[i][j]+num[i][id],ee[j][id]);
					ee[id][j]=min(ee[id][j],num[i][j]+num[i][id]);
					add(j,id,num[i][j]+num[i][id],i);
				}
			}	
		}
	}
	sort(e+1,e+tot+1,cmp);
	ll res1=0;
	kruskal();//不标记任何乡镇
	ans=res; 
	for(ll i=1;i<=k;i++){
		res=res1+c[i];
		lzt[i]=1;//设置为选了这个乡镇 
		kruskal();
		for(ll ii=1;ii<=k;ii++){
			if(lzt[ii]&&(!vis[ii])){
				res-=c[ii];
			}
		}
		if(ans>=res){//选用 
			res1+=c[i];
			ans=res;
			for(ll ii=1;ii<=k;ii++){
				if(lzt[ii]&&(!vis[ii])){
					lzt[ii]=0;
					res1-=c[ii];
				}
			}
		}
		else
			lzt[i]=0;
	}
	cout<<ans;
	return 0;
} 