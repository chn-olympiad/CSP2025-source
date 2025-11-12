#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace{
	int read(){
		int x=0;char c=0;
		while(c<'0'||c>'9') c = getchar();
		while(c>='0'&&c<='9') {
			x = x*10 +(c^48);
			c = getchar();
		}
		return x;
	}
	struct edge{
		int from,to,w;
	}e[2000005];
	int fa[100005];
	int c[11];
	int cnt;
	int getfa(int x){
		return fa[x] == x?x:fa[x] = getfa(fa[x]);
	}
	void add(int u,int v,int w){
		e[++cnt].from = u;
		e[cnt].to = v;
		e[cnt].w = w;
	}
	void solve(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		int n = read(),m = read(),k = read();
		for(int i = 1;i<=m;i++){
			int u= read(),v = read(),w =read();
			add(u,v,w);	
		}
		for(int i = 1;i<=k;i++){
			read();
			for(int j = 1;j<=n;j++){
				int t = read();
				add(n+i,j,t);
			}
		}
		sort(e +1,e+m+n*k+1,[](edge a,edge b)->bool{
			return a.w<b.w;
		});
		for(int i = 1;i<=n+k;i++){
			fa[i] = i;
		}
		ll ans = 0;
		for(int i = 1;i<=10;i++)c[i] = -2;
		for(int i = 1;i<=m+n*k;i++){
			//printf("%d %d %d\n",e[i].to,e[i].from,e[i].w);
			if(getfa(e[i].to)!=getfa(e[i].from)){
				if(e[i].from>n) {
					if(c[e[i].from - n]>0){
						ans+= c[e[i].from - n];
						c[e[i].from - n] = -1; 
					}else if(c[e[i].from - n]==-2){
						c[e[i].from - n]  = e[i].w;
						ans -= e[i].w;
					}
				}
				ans+=e[i].w;
				fa[getfa(e[i].to)] = getfa(e[i].from);
			} 
		}
		printf("%lld\n",ans);
	}
}
int main(){
	solve();
	return 0;
}

