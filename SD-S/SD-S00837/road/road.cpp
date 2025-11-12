#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char ch = getchar();
	while(ch<'0' || '9'<ch){
		if(ch == '-') f=-1;
		ch = getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x*f;
}
const int N=1e3+10,M=2e6+10,inf = 0x7f7f7f7f;
int n,m,k,a[15][N*10],c[15];
ll e[N][N];
int fa[N*10];
int findf(int x){
	return ( (fa[x] == x) ? x : (fa[x] = findf(fa[x]) ) );
}
struct Edge{
	int u,v;
	ll val;
}edge[M<<1];
bool cmp(Edge x,Edge y){
	return x.val<y.val;
}
ll ans = 0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i=1;i<=m;i++){
		edge[i].u = read(),edge[i].v = read(),edge[i].val= read();
	}
	memset(e,inf,sizeof(e));
	bool flag = true;
	for(int j=1;j<=k;j++){
		c[j] = read();
		if(c[j] != 0) flag = false;
		
		for(int i=1;i<=n;i++){
			a[j][i] = read();
			if(a[j][i] != 0) flag = false;
		} 
		if(flag){
			if(e[1][1] != 0) memset(e,0,sizeof(e));
			continue;
		} 
		
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				e[l][r] = min(e[l][r],a[j][l]*1ll+c[j]*1ll+a[j][r]*1ll);
//				edge[++m].u = l;
//				edge[m].v = r;
//				edge[m].val = a[j][l]*1ll+c[j]*1ll+a[j][r]*1ll;
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			edge[++m].u = l;
			edge[m].v = r;
			edge[m].val = e[l][r];
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++){
		int x = edge[i].u,y = edge[i].v;
		int fx = findf(x),fy = findf(y);
		if(fx == fy) continue;
		ans += edge[i].val;
		fa[fx] = fy;
	}
	cout<<ans<<"\n";
	return 0;
}

