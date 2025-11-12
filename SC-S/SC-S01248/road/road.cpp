#include<bits/stdc++.h>
using namespace std;
namespace solve{
	#define int long long
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int fa[10005];
	inline void init(int t){
		for(int i=1;i<=t;i++)
			fa[i]=i;
		return void();
	}
	int find(int x){
		if(fa[x]==x)return x;
		else return fa[x]=find(fa[x]);
	}
	inline void merge(int x,int y){
		if(find(x)!=find(y))
			fa[find(x)]=find(y);
		return void();
	}
	int n,m,k,rlt=0;
	struct Edge{
		int u,v,w;
	}edge[1050005];
	bool cmp(const Edge a,const Edge b){
		return a.w<b.w;
	}
	int c[15];
	vector<Edge>tree;
	int g[15][10005];
	inline bool get(int x,int pos){
		pos--;
		return (x&(1<<pos))>>pos;
	}
	inline signed solve(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		n=read();m=read();k=read();
		init(n);
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),w=read();
			edge[i]={u,v,w};
		}
		bool vis=1;
		for(int i=1;i<=k;i++){
			c[i]=read();
			if(c[i]!=0)vis=0;
			for(int j=1;j<=n;j++){
				int w=read();
				g[i][j]=w;
			}
		}
		if(vis){
			init(n+k);
			for(int i=1;i<=k;i++)
				for(int j=1;j<=n;j++)
					edge[m+n*(i-1)+j]={n+i,j,g[i][j]};
			int uiop[15],mp[15];
			memset(mp,0,sizeof mp);
			sort(edge+1,edge+m+n*k+1,cmp);
			for(int i=1;i<=m+n*k;i++){
				int u=edge[i].u;
				int v=edge[i].v;
				int w=edge[i].w;
				if(find(u)!=find(v)){
					tree.push_back({u,v,w});
					merge(u,v);rlt+=w;
				}
			}
			for(auto i:tree){
				if(i.u>n){
					mp[i.u-n]++;
					uiop[i.u-n]=i.w;
				}
				if(i.v>n){
					mp[i.v-n]++;
					uiop[i.v-n]=i.w;
				}
			}
			for(int i=1;i<=k;i++)
				if(mp[i]==1)rlt-=uiop[i];
			cout<<rlt<<endl;
			return 0;
		}
		return 0;
	}
	#undef int
}
int main(){return solve::solve();}
