#include<bits/stdc++.h>
#define int long long
#define signed bool __End;signed
using namespace std;
bool __Begin;
namespace _IO{inline int read(){int f=1,res=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}return f*res;}void write(int x){if(x<0){putchar('-');write(-x);}else if(x<=9){putchar(x+'0');}else{write(x/10);putchar(x%10+'0');}return;}}
namespace _Min{int Min(int x,int y){return x<y?x:y;}int Max(int x,int y){return x>y?x:y;}}
namespace _edge{struct edge{int u,v,w;}e[2000005];int first[2000005],nxt[2000005],cnt;void add(int u,int v,int w){cnt++,e[cnt]={u,v,w};nxt[cnt]=first[u];first[u]=cnt;return;}void edge_clear(){cnt=0;memset(first,-1,sizeof(first));return;}}

using namespace _IO;
using namespace _Min;
using namespace _edge;

int n,m,K,ans;
int c[2000005],a[11][20005];
int fa[2000005];
int dep[2000005];
vector<edge>tmp,kk;
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
namespace sub1{
	void solve(){
		int ans=1e18;
		for(int i=0;i<(1<<K);i++){
			for(int j=1;j<=n+K;j++){
				fa[j]=j,dep[j]=1;
			}
			tmp.clear();
			int res=0;
			for(int j=1;j<=K;j++){
				if((i>>(j-1))&1){
					res+=c[j];
					for(int k=1;k<=n;k++){
						tmp.push_back({n+j,k,a[j][k]});
					}
				}
			}
			for(int j=1;j<=m;j++){
				tmp.push_back({e[j].u,e[j].v,e[j].w});
			}
			sort(tmp.begin(),tmp.end(),[](edge x,edge y){return x.w<y.w;});
			for(auto it:tmp){
				int u=it.u,v=it.v,w=it.w;
				int fu=find(u),fv=find(v);
				if(fu==fv)continue;
				if(dep[fu]<dep[fv]){
					swap(u,v),swap(fu,fv);
				}
				fa[fv]=fu;
				res+=w;
				dep[fu]=Max(dep[fu],dep[fv]+1);
			}
			ans=Min(ans,res);
		}
		write(ans);
		return;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=n*2+K*2;i++){
		fa[i]=i,dep[i]=1;
	}
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=K;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	sub1::solve();
//	cerr<<"\n"<<(clock())<<"ms "<<(((&__Begin)-(&__End))>>20)<<"MB\n";
	return 0;
}
