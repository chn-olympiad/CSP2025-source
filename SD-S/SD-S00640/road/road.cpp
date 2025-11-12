#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>47) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

const int N=1e4+14;
const int M=1e6+6;
const int K=12;
const int inf=1e17;
int n,m,k,h[N+K],tot,fa[N+K],W[N+K];
struct sw{
	int u,v,w,nxt;
}e[2*M+K*N];

inline void add(int u,int v,int w){
	e[++tot]={u,v,w,h[u]};h[u]=tot;
}

inline int FIND(int x){
	return (x==fa[x]?x:fa[x]=FIND(fa[x]));
}

inline bool check(int u,int v,int S){
	if(u<=n&&v<=n){
		return 1;
	}
	else if(u>n&&v<=n){
		int x=u-n-1;
		if((S&(1<<x))){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int y=v-n-1;
		if((S&(1<<y))){
			return 1;
		}
		else{
			return 0;
		}
	}
}

inline bool cmp(sw x,sw y){
	return x.w<y.w;
}

inline int solve(int S){
	int res=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		if((S&(1<<(i-1)))){
			res+=W[i+n];
		}
	}
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v;
		if(check(u,v,S)){
			int fu=FIND(u),fv=FIND(v);
			if(fu!=fv){
				res+=e[i].w;
				fa[fu]=fv;
			}
		}
	}
	return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		W[n+i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			add(i+n,j,w);
			add(j,i+n,w);
		}
	}
	sort(e+1,e+tot+1,cmp);
	
	if(k==0){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int ans=0;
		for(int i=1;i<=tot;i++){
			int u=e[i].u,v=e[i].v;
			int fu=FIND(u),fv=FIND(v);
			if(fu!=fv){
				ans+=e[i].w;
				fa[fu]=fv;
			}
		}
		printf("%lld",ans);
	}
	else if(k<=10){
		int ans=inf;
		for(int S=0;S<(1<<k);S++){
			ans=min(ans,solve(S));
		}
		printf("%lld",ans);
	}
	return 0;
} 
