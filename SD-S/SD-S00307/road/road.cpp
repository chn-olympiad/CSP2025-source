#include<bits/stdc++.h>
#include<windows.h>
#define ll long long
#define sdn cout
#define pb push_back
using namespace std;
const int N = 1e4 + 100,M = 2e6 + 100,INF = 1e9 + 7;
int a[12][N],idx,n,m,k,op[11];
ll sm,ans;
struct edge{
	int x,y,z;
	bool operator <(const edge &p)const{
		return z < p.z;
	}
}e[M],e1[M];
vector <int> lk[N];
struct sorasaki_hina{
	int f[N],siz[N];
	void init(){
		for(int i = 1;i < N;i ++)  f[i] = i,siz[i] = 1;
	}
	int find(int x){
		if(f[x] != x)  f[x] = find(f[x]);
		return f[x];
	}
 	void mg(int x,int y){
		if(siz[x] > siz[y])  swap(x,y);
		f[x] = y,siz[y] += siz[x]; 
	}
}b;
inline void check(){
	sm = 0;b.init();
	vector <int> lk[12];
	int cnt = 1,x = 1,opt = n;
	for(int i = 1;i <= m;i ++){
		e1[i] = e[i];
	}
	int idx = m;
	for(int i = 1;i <= k;i ++){
		if(op[i]){
			sm += a[i][0];opt ++;
			for(int j = 1;j <= n;j ++){
				e1[++idx] = (edge){i+n,j,a[i][j]};
			}
		}
	}
	sort(e1+1,e1+idx+1);
	while(cnt < opt&&x<=idx){
		int u = e1[x].x,v = e1[x].y;
		int uu = b.find(u),vv = b.find(v);
		if(uu == vv){
			x ++;continue;
		}
		sm += e1[x].z;b.mg(uu,vv);
		if(u < v)  swap(u,v);
		if(u > n)  lk[u-n].pb(v);
		x ++;cnt ++;
	}
	for(int i = 1;i <= k;i ++){
		if(lk[i].size()==1)
		  sm -= (a[i][0]+a[i][lk[i][0]]);
	}
	ans = min(ans,sm);
}
inline void dfs(int x){
	if(x > k){
		check();
		return ;
	}
	op[x] = 0;dfs(x+1);
	op[x] = 1;dfs(x+1);
}
inline int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		x = x*10+(c-'0');
		c = getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	b.init();ans = 1e18;
	bool f = 1;
	n = read(),m = read(),k = read();
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		u = read(),v = read(),w = read();
		e[i] = (edge){u,v,w};
	}
	for(int i = 1;i <= k;i ++){
		for(int j = 0;j <= n;j ++){
			a[i][j] = read();
		}
		if(a[i][0] != 0)  f = 0;
		bool ff = 0;for(int j = 1;j <= n;j ++){
			if(a[i][j] == 0)  ff = 1;
		}
		f = f&ff;
	}
	if(f){
		for(int i = 1;i <= k;i ++){
			op[i] = 1;
		}
		check();
		sdn<<ans;
		return 0;
	}
	dfs(1);
	sdn<<ans<<endl;
	return 0;
}
