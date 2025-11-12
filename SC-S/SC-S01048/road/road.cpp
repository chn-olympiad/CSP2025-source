#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll N=2e6+5,K=15,INF=1e17+7;
struct oside{
	ll u,v,w;
	bool operator<(const oside &vr) const{
		return w<vr.w;
	}
}os[N],gs[N];
ll c[N];
ll glen;
ll f[N],siz[N];
ll ans=INF,sum;
ll find(ll x){
	return (f[x]==x?x:f[x]=find(f[x]));
}
ll n,m,k;
void merge(ll a,ll b){
	a=find(a),b=find(b);
	if(siz[a]<siz[b]) std::swap(a,b);
	siz[a]+=siz[b],f[b]=a;
	return ;
}
ll chs[N];
ll a[K][N];
void dfs(ll x){
	if(!x){
		for(ll i=1;i<=n+k;++i) f[i]=i,siz[i]=1;
		sum=0;
		glen=0;
		int ggt=0;
		for(ll i=1;i<=k;++i){
			if(chs[i]){
				sum+=c[i];
				++ggt;
				for(ll j=1;j<=n;++j){
					gs[++glen]={n+i,j,a[i][j]};
				}
			}
		}std::sort(gs+1,gs+glen+1);
		int cnt=0;
		for(ll i=1,j=1;i<=m||j<=glen;){
			oside t={0,0,0};
			if((j>glen)||(i<=m&&os[i].w<gs[j].w)){
				t=os[i];
				++i;
			}else{
				t=gs[j];
				++j;
			}if(find(t.u)!=find(t.v)){
				merge(t.u,t.v);
				sum+=t.w;
				++cnt;
			}
		}if(cnt!=n+ggt-1) return ;
		ans=std::min(ans,sum);
		return ;
	}chs[x]=1;
	dfs(x-1);
	chs[x]=0;
	dfs(x-1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(ll i=1,u,v,w;i<=m;++i){
		scanf("%lld%lld%lld", &u, &v, &w);
		os[i]={u,v,w};
	}std::sort(os+1,os+m+1);
	int nlen=0;
	for(ll i=1;i<=n;++i) f[i]=i,siz[i]=1;
	for(ll i=1;i<=m;++i){
			oside t=os[i];
		if(find(t.u)!=find(t.v)){
			merge(t.u,t.v);
			os[++nlen]=os[i];
		}
	}m=nlen;
	for(ll i=1;i<=k;++i){
		scanf("%lld", &c[i]);
		for(ll j=1;j<=n;++j) scanf("%lld", &a[i][j]);
	}
	dfs(k);
	printf("%lld\n", ans);
	return 0;
}