#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define Fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define fre(k) freopen(k".in","r",stdin),freopen(k".out","w",stdout)
using namespace std;
const int N=2e5+10,M=2e6+10;
int n,m,k,c[12],f[N],vis[12],cnt,ans,mi,id;
struct node{int u,v,w,d,fl;}g[M];
bool cmp(node a,node b){return a.w<b.w;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector<node> q[12];
signed main(){
	fre("road");
	Fast;cin>>n>>m>>k;cnt=m;
	rep(i,1,n+k) f[i]=i;
	rep(i,1,m) cin>>g[i].u>>g[i].v>>g[i].w;
	rep(i,1,k){
		cin>>c[i];mi=1e18;
		rep(j,1,n){
			cin>>g[++cnt].w;
			g[cnt].u=n+i;g[cnt].v=j;g[cnt].d=k;
			if(g[cnt].w<mi){mi=g[cnt].w;id=cnt;}
		}
		g[id].w+=c[i],g[id].fl=1;
	}
	sort(g+1,g+cnt+1,cmp);
	rep(i,1,cnt){
		if(g[i].d!=0&&!vis[g[i].d]){
			if(g[i].fl){
				for(auto j:q[g[i].d]){
					int x=find(j.u),y=find(j.v);
					if(x!=y) ans+=j.w,f[x]=y;
				}vis[g[i].d]=1;
			}else{q[g[i].d].push_back(g[i]);continue;}
		}
		int x=find(g[i].u),y=find(g[i].v);
		if(x!=y) ans+=g[i].w,f[x]=y;
		//cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
