#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=1e4+15;
const ll M=2e6+5;
const long long  inf=1e10;
ll c[15],b[15][N];
ll to=0,too=0;
struct nod{
	ll u,v,w;
}g[M],gh[M];
ll n,m,k;
bool cmp(nod x,nod y){
	return x.w<y.w;
}
ll fa[N],siz[N];
ll fd(ll x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
long long ans=0;
void hb(ll u,ll v,ll w){
	ll fu=fd(u),fv=fd(v);
	if(fu==fv)return ;
//	cout<<u<<" "<<v<<" "<<w<<"\n";
//	if(u==0)gh[v-n]=0;
	if(siz[fu]>siz[fv])swap(fu,fv);
	siz[fv]+=siz[fu];
	fa[fu]=fv;
	ans+=w;
}
void hbb(ll u,ll v,ll w){
	ll fu=fd(u),fv=fd(v);
	if(fu==fv)return ;
//	cout<<u<<" "<<v<<" "<<w<<"\n";
//	if(u==0)gh[v-n]=0;
	gh[++too]=(nod){u,v,w};
	if(siz[fu]>siz[fv])swap(fu,fv);
	siz[fv]+=siz[fu];
	fa[fu]=fv;
	ans+=w;
}
void solv(){
	sort(g+1,g+1+to,cmp);
	for(ll i=0;i<=n+k;i++)fa[i]=i,siz[i]=1;
	for(ll i=1;i<=to;i++)
		hb(g[i].u,g[i].v,g[i].w);
}
void sol(){
	long long an=inf;
	ll tot=to;
	for(ll i=0;i<(1<<k);i++){
//		ll an=0;
		to=tot;
		ans=0;
		ll kp=0;
		for(ll j=1;j<=k;j++){
			if((i>>(j-1))&1){
				kp+=c[j];
				for(ll r=1;r<=n;r++){
					g[++to]=(nod){j+n,r,b[j][r]};
				}
			}
		}
		solv();
		an=min(ans+kp,an);
	}
	cout<<an<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		++to;
		cin>>g[to].u>>g[to].v>>g[to].w;
	}
	if(m<=100000)sol;
	else{
		sort(g+1,g+1+to,cmp);
		for(ll i=0;i<=n+k;i++)fa[i]=i,siz[i]=1;
		for(ll i=1;i<=to;i++)
			hbb(g[i].u,g[i].v,g[i].w);
		for(ll i=1;i<=too;i++)g[i]=gh[i];
		to=too;
		for(ll i=1;i<=k;i++){
			cin>>c[i];
			for(ll j=1;j<=n;j++)cin>>b[i][j];
		}
	//	if(k<=5)
		sol();
	}
	return 0;
}
/*
14:55
ÖìÏéÈð,***¸öÎÚÑ»×ì£¬»¹Õæ**¿¼Í¼ÂÛÁË 
*/ 
