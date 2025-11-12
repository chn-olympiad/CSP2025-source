#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline ll min(ll x,ll y){
	return x<y?x:y;
}
const int N=1e4+15,M=1e6+5;
ll T=1,n,m,k,c[15],a[15][N],fa[N],ans=1e18,res;
bitset<N>vis;
struct node{
	ll u,v,w;
	bool operator< (const node& g) const {
		return w<g.w;
	}
}b[M],d[M];
//ll cnt=1,head[N];
//struct edge{
//	ll to,next,w;
//}e[M<<1];
//inline void add(ll u,ll v,ll w){
//	e[cnt].to=v;
//	e[cnt].w=w;
//	e[cnt].next=head[u];
//	head[u]=cnt++;
//}
inline ll finds(ll x){
	return x==fa[x]?x:fa[x]=finds(fa[x]);
}
inline void dfs(ll x,ll sum,ll y){
	if(x>k){
		ll num=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=res;i++){
			ll x=finds(d[i].u),y=finds(d[i].v);
			if(vis[x]&&vis[y]&&x!=y){
				fa[x]=y;
				sum+=d[i].w;
				num++;
				
//				write(d[i].u);
//				putchar(' ');
//				write(d[i].v);
//				putchar(' ');
//				write(d[i].w);
//				putchar('\n');
				
				if(num==m-1+y) break;
			}
		}
//		if(sum){
//			write(sum);
//			putchar('\n');
//			for(int i=1;i<=k;i++){
//				write(vis[i+n]);
//				putchar(' ');
//			}
//			putchar('\n');
//		}
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,sum,y);
	vis[x+n]=true;
	dfs(x+1,sum+c[x],y+1);
	vis[x+n]=false;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=n;i++){
			fa[i]=i;
			vis[i]=true;
		}
		for(int i=1;i<=m;i++){
			ll u=read(),v=read(),w=read();
//			add(u,v,w);
//			add(v,u,w);
			b[i].u=u;
			b[i].v=v;
			b[i].w=w;
		}
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				a[i][j]=read();
			}
		}
		sort(b+1,b+1+m);
		for(int i=1;i<=m;i++){
			ll x=finds(b[i].u),y=finds(b[i].v);
			if(x!=y){
				fa[x]=y;
				d[++res]=b[i];
				if(res==m-1) break;
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				res++;
				d[res].u=j;
				d[res].v=n+i;
				d[res].w=a[i][j];
			}
		}
		sort(d+1,d+1+res);
		dfs(1,0,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}
