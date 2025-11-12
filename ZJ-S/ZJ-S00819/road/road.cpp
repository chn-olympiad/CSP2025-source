#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define eb emplace_back
const int N=1e4+10,M=1e6+10;
struct edge{int u,v,w;}e[M<<1],cho[N];
int n,m,k,cnt;
ll res,ans=1e18;
int v[20],w[20][N];
inline bool cmp(edge p,edge q){return p.w<q.w;}
int f[N+10],size[N+10];
int gf(int u){return f[u]==u?u:f[u]=gf(f[u]);}
inline void merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x!=y){
		if(size[x]>size[y]) swap(x,y);
		f[x]=y,size[y]+=size[x];
	}
}
inline void Ku(int mx,int num,int b){
//	clog <<"start"<<mx<<' '<<num<<' '<<b<<endl;
	cnt=0;
	sort(e+1,e+mx+1,cmp);
	for(int i=1;i<=num;i++) f[i]=i,size[i]=1;
	for(int i=1;i<=mx;i++){
		int u=e[i].u,v=e[i].v;
		if(gf(u)!=gf(v)){
//			clog <<"choose"<<u<<' '<<v<<' '<<e[i].w<<"\n";
			merge(u,v);res+=e[i].w;
			if(res>ans) return;
			if(!b) cho[++cnt]=e[i];
			if(cnt==num-1) break;
		}
	}
}
inline int read(){
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++) cin>>w[i][j];
	}
	Ku(m,n,0);ans=res;
//	clog <<"ans="<<ans<<' '<<(double)clock()/CLOCKS_PER_SEC<<endl;
	for(int i=(1<<k)-1;i;i--){
		int c=0;res=0;
		for(int j=1;j<n;j++) e[j]=cho[j];
		for(int ii=1;ii<=k;ii++){
			if(i&(1<<ii-1)){
				c++,res+=v[ii];
				for(int j=1;j<=n;j++) e[j+c*n-1]={n+c,j,w[ii][j]};
			}
		}
		Ku(n-1+c*n,n+c,i);
		if(res<ans) ans=res;
		for(int j=1;j<n;j++) e[j]=cho[j];
//		if((double)clock()/CLOCKS_PER_SEC>0.9) break;
//		clog <<"ans="<<ans<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
