#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i = l; i<=r; i++)
#define ROF(i,r,l) for(int i = r; i>=l; i--)
#define all(x) x.begin(),x.end()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,f=1;
    while(!isdigit(ch)) {
    	if(ch=='-') f=-1;
    	ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
bool ST;
const int N = 1e4+15;
struct edge{
	int u, v,w;
	bool operator < (const edge b)const{
		return w<b.w;
	}
};
vector<edge> vc[15];
int fa[N],n,m,k,sz[N], c[15], a[15][N],nn;
long long ans = 0x3f3f3f3f3f3f3f3f;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}
void unio(int x, int y){
	x=find(x),y=find(y);
	if(sz[x]<sz[y]){
		fa[x] = y;
		sz[y]+=sz[x];
	}else{
		fa[y] = x;
		sz[x]+=sz[y];
	}
}
void sol(int x, long long add, int n){
	sort(all(vc[x]));
	vc[x+1].clear();
	FOR(i,1,n+k)fa[i] = i,sz[i]=1;
	int cnt = 0,u,v,w;
	long long res = 0;
	for(auto p:vc[x]){
		u = p.u,v=p.v,w=p.w;
		if(find(u)!=find(v)){
			unio(u,v);
			res+=w;
			vc[x+1].push_back(p); 
			if(++cnt==n-1)break;
		}
	}
	cmin(ans,res+add);
}
void dfs(int x, long long add, int n){
	if(add>=ans||x>k)return;
	vc[x+1] = vc[x];
	dfs(x+1,add,n);
	FOR(i,1,nn){
		vc[x].push_back({x+nn,i,a[x][i]});
	} 
	add += c[x];
	n++;
	sol(x,add,n);
	dfs(x+1,add,n);
}
bool ED;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	nn=n;
	int u,v,w;
	FOR(i,1,m){
		u = read(),v=read(),w=read();
		vc[0].push_back({u,v,w});
	}
	FOR(i,1,k){
		c[i] = read();
		FOR(j,1,n)a[i][j] = read();
	}
	sol(0,0,n);
	dfs(1,0,n);
	cout<<ans<<"\n";
//	cerr << "\nused: " <<abs(&ST-&ED)/1024/1024<<" MB\n";
	return 0;
}



