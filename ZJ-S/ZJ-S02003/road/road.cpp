#include<bits/stdc++.h>
#define ll long long
#define gc getchar
using namespace std;
const int N=10010,M=1000010,K=20;
void in(int &x){
	x=0;char c;
	while((c=gc())<'0'||c>'9');
	while(c>='0'&&c<='9')x=x*10+(c^48),c=gc();
}
int n,m,k;
int c[K],a[K][N];
//ll dp[K][M];
//ll dp[N];
//bool vis[N];
//struct nn{int v,w;};
//vector<nn>g[N+K];
struct mm{int u,v,w;};
vector<mm>tt,t;
int fa[N];
bool vis[K],f[M];
int find(int x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
bool cmp(mm x,mm y){return x.w<y.w;}
//ll Prim(){
//	ll ans=0;
//	dp[1]=0ll;
//	for(int i=2;i<=n;++i){
//		dp[i]=LONG_LONG_MAX;
//	}
//	for(int i=1;i<=n;++i)vis[i]=false;
//	for(int i=1;i<=n;++i){
//		ll mn=LONG_LONG_MAX;
//		int u=-1;
//		for(int j=1;j<=n;++j)
//			if(dp[j]<mn&&!vis[j]){
//				mn=dp[j];
//				u=j;
//			}
//		ans+=mn;
//		for(int j=0;j<(int)g[u].size();++j){
//			int v=g[u][j].v,w=g[u][j].w;
//			if(!vis[v]&&dp[u]+w<dp[v])
//				dp[v]=dp[u]+dis[j];
//		}
//	}
//	return ans;
//}
ll Kus(){
	ll ans=0;int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(tt.begin(),tt.end(),cmp);
	for(int i=0;i<(int)tt.size();i++){
		int u=tt[i].u,v=tt[i].v,w=tt[i].w;
		if(find(u)==find(v))continue;
		merge(u,v);
		ans+=w;
//		if((u<=n||u>n&&vis[u-n])&&(v<=n||v>n&&vis[v-n])){
//			if(u>n){
//				ans-=c[u-n];
//			}else if(v>n){
//				ans-=c[v-n];
//			}
			if(++cnt==n-1)
				return ans;
//		}else{
//			if(v>n){
//				if(!vis[v-n]){
//					ans+=c[v-n],vis[v-n]=true;
//					++cnt;
//				}else{
//					if(--cnt==0)
//						return ans;
//				}
//			}else{
//				if(!vis[u-n]){
//					ans+=c[u-n],vis[u-n]=true;
//					++cnt;
//				}else{
//					if(--cnt==0)
//						return ans;
//				}
//			}
//		}
	}
//	return 114514ll;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n);in(m);in(k);
	for(int i=1,u,v,w;i<=m;++i){
		in(u),in(v),in(w);
		tt.push_back((mm){u,v,w});
//		g[u].push_back((nn){v,w});
//		g[v].push_back((nn){u,w});
	}
	for(int i=1;i<=k;++i){
		in(c[i]);
		for(int j=1;j<=n;++j){
			in(a[i][j]);
//			tt.push_back((mm){i+n,j,w+c[i]});
//			g[i+n].push_back((nn){j,w});
//			g[j].push_back((nn){i+n,w});
		}	
	}
	t=tt;
//	ll ans=114514;
	ll ans=Kus();
//	for(int i=0;i<(int)tt.size();++i){
//		int u=tt[i].u,v=tt[i].v;
//		for(int j=1;j<=k;j++){
//			if(a[j][u]+a[j][v]<tt[i].w){
//				tt[i]={u,v,a[j][u]+a[j][v],j};
//			}
//		}
//	}
	for(int x=1;x<=k;x++){
		tt=t;
		for(int i=0;i<(int)tt.size();++i){
			int u=tt[i].u,v=tt[i].v;
			if(a[x][u]+a[x][v]<tt[i].w){
				tt[i]={u,v,a[x][u]+a[x][v]};
			}
		}
		ll tmp=c[x]+Kus();
		if(tmp<=ans){
			ans=tmp;
			t=tt;
		}
	}
//	ll ans=Kus(1);
//	for(int i=0;i<(int)tt.size();++i)
//		if(f[i]&&tt[i].f){
//			ans+=c[tt[i].f];
//		}
	printf("%lld",ans);
	return 0;
}
