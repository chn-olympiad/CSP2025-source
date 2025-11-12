#include<bits/stdc++.h>
#define pii pair<int,int>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
bool bst; 
ll R(){
	ll f=1,w=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-f;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10-'0'+c;c=getchar();}
	return w*f;
}
void W(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) W(x/10);
	putchar(x%10+'0');
}
int const N=2e4+10,M=1e6+10,K=13;
struct edge{
	int u,v,w;
	bool operator < (const edge &b) const{
		return w<b.w;
	}
}e[M],ne[K*N],tmp[M];
struct DSU{
	int fa[N],sz[N];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;}
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	bool mg(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return 0;
		if(sz[u]<sz[v]) swap(u,v);
		fa[v]=u,sz[u]+=sz[v];
		return 1;
	}
}dsu;
int a[N],b[K][N];
bool bed;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	clock_t st=clock();
	int n=R(),m=R(),k=R(),cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=R(),v=R(),w=R();
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1);
	dsu.init(n);
	for(int i=1;i<=m;i++){
		if(dsu.mg(e[i].u,e[i].v)){
			ans+=e[i].w;
			tmp[++cnt]=e[i];
		}
	}
	for(int i=1;i<n;i++) e[i]=tmp[i];
//	printf("ori=%lld\n",ans);
	for(int i=0;i<k;i++){
		a[i]=R();
		for(int j=1;j<=n;j++){
			int w=R();
			ne[i*n+j]={i,j,w};
		}
	}
	sort(ne+1,ne+n*k+1);
	for(int i=1;i<=n*k;i++){
		b[ne[i].u][ne[i].v]=i;
	}
	for(int i=1;i<(1<<k);i++){
		ll sum=0;
		int x=1,y=1,now=n-1;cnt=0;
		for(int j=0;j<k;j++){
			if(i>>j&1) sum+=a[j],now++;
		}
//		cout<<now<<endl;
		dsu.init(n+k);
		while(x<n&&y<=n*k&&sum<ans&&cnt<now){
			while(y<=n*k&&!(i>>ne[y].u&1)) ++y;
			if(x<n&&(y>n*k||e[x].w<ne[y].w)){
				if(dsu.mg(e[x].u,e[x].v)){
					cnt++,sum+=e[x].w;
//					printf("1=%d\n",e[x].w);
				}
				x++;
			}
			else{
				if(dsu.mg(ne[y].u+n+1,ne[y].v)){
					cnt++,sum+=ne[y].w;
//					printf("2=%d\n",ne[y].w);
				}
				y++;
			}
		}
//		cout<<cnt<<endl;
//		printf("i=%d sum=%lld\n",i,sum);
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
//	clock_t ed=clock();
//	cerr<<(double)(ed-st)/1000.0<<endl;
//	cerr<<"size="<<(double)(&bst-&bed)/1024/1024.0<<endl;
	return 0;
}
/*
 
*/
