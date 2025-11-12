#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define fir first
#define sec second
#define file(_1) freopen(_1".in","r",stdin),freopen(_1".out","w",stdout);
#define error(_) cerr<<_<<endl
#define look_memory cerr<<(&m2-&m1)/1024.00/1024.0<<"MB"<<endl;
#define look_time cerr<<(t2-t1)/1000.0<<"s"<<endl;
using namespace std;
template <typename T>
inline void read(T &x){
	T f=1,c=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=getchar();
	}
	x=f*c;
}

template<typename T,typename ...Args>
inline void read(T &x,Args &...args){
	read(x),read(args...);
}
namespace white_carton{
	struct edge{
		int u,v,w;
		friend bool operator<(const edge a,const edge b){
			return a.w<b.w;
		}
	}s;
	vector<edge> E1,E2,E;
	int cnt,n,m,k,fa[20010];
	int find(int u){
		return fa[u]==u?fa[u]:fa[u]=find(fa[u]);
	}
	int in[50010],vis[20];
	void init(){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			in[i]=0;
		}
	}
	int krusl(){
		init();
		sort(E1.begin(),E1.end());
		int ans=0;
		for(auto s:E1){
			int u=s.u,v=s.v,w=s.w;
			u=find(u),v=find(v);
			if(u==v){
				continue;
			}
			in[u]++,in[v]++;
			ans+=w;
			fa[u]=v;
			E2.pb(s);
		}
		return ans;
	}
	int c[20],w[20][10010];
	void solve(){
		read(n,m,k);
		for(int i=1;i<=m;i++){
			read(s.u,s.v,s.w);
			E1.pb(s);
		}
		for(int i=1;i<=k;i++){
			read(c[i]);
			for(int j=1;j<=n;j++){
				read(w[i][j]);
			}
		}
		int ans=krusl();
		E=E2;
		int s=(1<<k)-1;
		for(int i=1;i<=s;i++){
			E2=E;
			int ans0=0;
			for(int j=1;j<=k;j++){
				if(i&(1<<(j-1))){
					ans0+=c[j];
					for(int s=1;s<=n;s++){
						E2.pb({n+j,s,w[j][s]});
					}
				}
			}
			swap(E1,E2);
			ans0+=krusl();
			ans=min(ans,ans0);
		}
		cout<<ans<<endl;
	}
}
int T=1;
signed main(){
	file("road");
//	read(T);
	while(T--){
		white_carton::solve();
	}
}
//1.快读
//2.注意空间
//3.多测清数据
//4.对拍
//5.打满暴力
//6.文件
//7. RP++;



//starback24

