#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=10100,MAXM=1000100,MAXK=15;
ll n,m,k,c[MAXK],a[MAXK][MAXN],fa[MAXN],pre[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct Edge{
	ll u,v,w;
}e1[MAXM],e2[MAXN],e3[MAXK*MAXN];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
//vector<ll>G1[MAXN],G2[MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=0;i<m;i++){
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	}
	for(ll i=0;i<k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e1,e1+m,cmp);
	for(ll i=0,cur=0;i<m;i++){
		ll u=e1[i].u,v=e1[i].v,w=e1[i].w,fau=find(u),fav=find(v);
		if(fau==fav)continue;
		e2[cur].u=u,e2[cur].v=v,e2[cur].w=w,cur++,fa[fau]=fav;
	}
	ll ans=LLONG_MAX;
	for(ll i=0;i<pre[k];i++){
//		cout<<"\nAtt"<<i<<":\n";
		ll cost=0,AddedVillage=0;
		for(ll j=0;j<n-1;j++)e3[j].u=e2[j].u,e3[j].v=e2[j].v,e3[j].w=e2[j].w;
		for(ll j=0;j<k;j++){
			if(i&pre[j]){
				cost+=c[j];
				for(ll v=1;v<=n;v++){
					e3[AddedVillage*n+v+n-2].u=n+j+1;
					e3[AddedVillage*n+v+n-2].v=v;
					e3[AddedVillage*n+v+n-2].w=a[j][v];
				}
				AddedVillage++;
			}
		}
		sort(e3,e3+AddedVillage*n+n-1,cmp);
//		for(ll j=0;j<AddedVillage*n+n-1;j++){
//			cout<<e3[j].u<<' '<<e3[j].v<<' '<<e3[j].w<<'\n';
//		}
		for(ll j=0;j<=n+k;j++){
			fa[j]=j;
		}
//		cout<<'\n';
		for(ll j=0,cur=0;j<AddedVillage*n+n-1&&cur<n+AddedVillage-1;j++){
			ll u=e3[j].u,v=e3[j].v,w=e3[j].w,fau=find(u),fav=find(v);
			if(fau==fav)continue;
//			cout<<e3[j].u<<' '<<e3[j].v<<' '<<e3[j].w<<'\n';
			cost+=w,cur++,fa[fau]=fav;
		}
//		cout<<cost<<'\n';
		ans=min(ans,cost);
	}
	cout<<ans;
	return 0;
}
