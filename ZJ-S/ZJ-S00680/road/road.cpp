#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=1e4+9,M=1e6+9;
int n,m,k,cnt,cntt,fa[N+20],c[20],w[20][N],a[20];ll ans=4e18;
struct ed{int u,v,w;}e[M],ee[N*11],tmp[N*11];
bool operator<(ed x,ed y){return x.w<y.w;}
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void dfs(int x){
	if(x>k){
		ll sum=0;
		memcpy(tmp,ee,sizeof tmp),cntt=cnt;
		for(int i=1;i<=k;i++)if(a[i]){
			sum+=c[i];
			for(int j=1;j<=n;j++)tmp[++cntt]={n+i,j,w[i][j]};
		}sort(tmp+1,tmp+cntt+1);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		//for(int i=1;i<=cntt;i++)cerr<<tmp[i].u<<' '<<tmp[i].v<<' '<<tmp[i].w<<'\n';
		for(int i=1,ln=0;i<=cntt;i++){
			int u=tmp[i].u,v=tmp[i].v,fu=fd(u),fv=fd(v);
			if(fu^fv)fa[fu]=fv,++ln,sum+=tmp[i].w;//,cerr<<u<<' '<<v<<' '<<tmp[i].w<<"olo\n";
			if(ln==n+k-1)break;
		}//for(int i=1;i<=k;i++)cerr<<a[i];
		//cerr<<':'<<sum<<'\n';
		ans=min(ans,sum);return;
	}a[x]=1,dfs(x+1),a[x]=0,dfs(x+1);
}
int main(){freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(cin.tie(cout.tie()));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>w[i][j];
	}
	sort(e+1,e+m+1);
	for(int i=1,ln=0;i<=m;i++){
		int u=e[i].u,v=e[i].v,fu=fd(u),fv=fd(v);
		if(fu^fv)fa[fu]=fv,ee[++cnt]={u,v,e[i].w},++ln;
		if(ln==n-1)break;
	}dfs(1);
	cout<<ans;
	return 0;
}
