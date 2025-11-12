#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
inline ll read(){
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
struct ND{
	ll a,b,w;
};
bool cmp(ND x,ND y){
	return x.w<y.w;
} 
ll fa[N],siz[N],ans,kk[20][N];
ll findfa(ll x){
	return fa[x]==x? fa[x] : fa[x]=findfa(x);
}
ND bian[N];
ll n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(ll i=1;i<=m;i++){
		bian[i].a=read();bian[i].b=read();bian[i].w=read();
	}
	for(ll i=1;i<=k;i++){
		kk[i][0]=read();
		for(ll j=1;j<=n;j++){
			kk[i][j]=read();
		}
	}
	for(ll i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	sort(bian+1,bian+1+m,cmp);
	for(ll i=1;i<=m;i++){
		ll fx=findfa(fa[bian[i].a]);
		ll fy=findfa(fa[bian[i].b]);
		if(fx!=fy){
			if(siz[fx]>siz[fy]) {
			    fa[fy]=fx;
			    siz[fx]+=siz[fy];
			}
			else{
				fa[fx]=fy;
				siz[fy]+=siz[fx];
			}
			ans+=bian[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
