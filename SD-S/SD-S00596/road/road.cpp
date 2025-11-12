#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1500005;
ll cunt[15];
ll X[1000005],Y[1000005],Z[1000005];
ll cheng[11][10005];
ll FLAG=1;
ll fa[N];
int vis[N];
int forbi[15000];
ll Find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
ll read(){
	ll ans=0;
	char ch;
	while(!(ch>='0'&&ch<='9')){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
struct node{
	ll x;
	ll y;
	ll w;
	node(){
		x=0;y=0;w=0;
	}
	node(ll dx,ll dy,ll dw){
		x=dx;y=dy;w=dw;
	}
	bool operator<(const node &b)const{
		return w<b.w;
	}
}edge[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cunt[1]=1;
	for(int i=2;i<=12;i++){
		cunt[i]=cunt[i-1]*2;
	}
	ll n,m,k;
	n=read();
	m=read();
	k=read();
//	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		X[i]=read();
		Y[i]=read();
		Z[i]=read();
//		scanf("%lld%lld%lld",&X[i],&Y[i],&Z[i]);
	}
	for(ll i=1;i<=k;i++){
//		scanf("%lld",&cheng[i][0]);
		cheng[i][0]=read();
		ll MINNN=10000000000000;
		for(ll j=1;j<=n;j++){
			cheng[i][j]=read();
//			scanf("%lld",&cheng[i][j]);
			MINNN=min(MINNN,cheng[i][j]);
		}
		if(!(cheng[i][0]==0&&MINNN==0)){
			FLAG=0;
		}
	}
	ll idx=0;
	if(!(FLAG==1||k==0)){
		ll minn=100000000000000000;
		for(ll i=1;i<=m;i++){
			edge[++idx]=node(X[i],Y[i],Z[i]);
		}
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				edge[++idx]=node(i+n,j,cheng[i][j]);
			}
		}
		sort(edge+1,edge+idx+1);
		for(ll i=0;i<cunt[k+1];i++){
//		for(ll i=1;i<=1;i++){
			for(int j=1;j<=n+k;j++){
				fa[j]=j;
			}
			ll ans=0;
			for(ll j=1;j<=k;j++){
				if(i&(cunt[j])){
					forbi[j+n]=0;
					ans+=cheng[j][0];
				}
				else{
					forbi[j+n]=1;
				}
			}
			for(int j=1;j<=idx;j++){
				ll x=edge[j].x;
				ll y=edge[j].y;
				ll z=edge[j].w;
				if(forbi[x]==1||forbi[y]==1){
					continue;
				}
				vis[x]=1;
				vis[y]=1;
				ll fx=Find(x);
				ll fy=Find(y);
				if(fx==fy){
					continue;
				}
				else{
					ans+=z;
					fa[fx]=fy;
				}
			}
//			for(int i=1;i<=n;i++){
//				if(vis[i]==0) cout<<"!";
//			}
//			cout<<ans<<endl;
			minn=min(minn,ans);
		}
//		for(int i=1;i<=n;i++){
//			
//		}
		printf("%lld",minn);
		return 0;
	}
	for(ll i=1;i<=n+k;i++){
		fa[i]=i;
	}
	if(FLAG==1){
		for(ll i=1;i<=m;i++){
			edge[++idx]=node(X[i],Y[i],Z[i]);
		}
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				edge[++idx]=node(i+n,j,cheng[i][j]);
			}
		}
	}
	if(k==0){
		for(ll i=1;i<=m;i++){
			edge[++idx]=node(X[i],Y[i],Z[i]);
		}
	}
	sort(edge+1,edge+idx+1);
	ll ans=0;
	for(ll i=1;i<=idx;i++){
		ll x=edge[i].x;
		ll y=edge[i].y;
		ll z=edge[i].w;
		ll fx=Find(x);
		ll fy=Find(y);
		if(fx==fy){
			continue;
		}
		else{
			ans+=z;
			fa[fx]=fy;
		}
	}
	printf("%lld",ans);
	return 0;
}
