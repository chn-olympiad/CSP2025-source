#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repn(x) rep(x,1,n)
#define pii pair<int,int>
#define fir first
#define sec second
const int N=1e4+7,inf=1e18+7;
vector<pii> e[N];
int n,m,k,ans=inf;
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return w*f;
}
int c[11],a[11][N],vis[N],dis[N],use[11];
priority_queue<pii,vector<pii>,greater<pii> >q;
int BST(int tt){
	int res=0,now=1;
	rep(i,1,n+k) vis[i]=0;
	rep(i,1,n+k) dis[i]=1e18+7;
	dis[1]=0;
	while(!q.empty()) q.pop();
	q.push({0,1});
//	cout<<n+tt<<"werew\n";
	for(int cnt=1;cnt<=n+tt;){
		int u=q.top().sec,w=q.top().fir;q.pop();
		if(vis[u]) continue;
		res+=w;
		vis[u]=1;
		cnt++;
		for(auto v:e[u]){
			if((v.fir>n&&use[v.fir-n]==0)||vis[v.fir]){
				continue;
			}
			dis[v.fir]=min(dis[v.fir],v.sec);
//			cout<<"v.fir="<<v.fir<<"v.sec="<<v.sec<<"\n";
//			cout<<"dis["<<v.fir<<"]="<<dis[v.fir]<<"\n";
			q.push({dis[v.fir],v.fir});
		}
	}
	return res;
}
void cal(){
	int nowcost=0,tt=0;
	rep(i,1,k) if(use[i]==1) nowcost+=c[i],tt++;
//	cout<<"t&n"<<tt<<" "<<nowcost<<"\n";
	int ttt=nowcost+BST(tt);
//	cout<<ttt<<"\n";
	ans=min(ans,ttt);
}
void dfs(int step){
	if(step==k+1){
		cal();
		return;
	}
	use[step]=1;
	dfs(step+1);
	use[step]=0;
	dfs(step+1);
}
void solve(){
	dfs(1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	rep(i,1,m){
		int u,v,w;
		u=read(),v=read(),w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	rep(i,1,k){
		c[i]=read();
		rep(j,1,n) a[i][j]=read(),e[i+n].push_back({j,a[i][j]}),e[j].push_back({i+n,a[i][j]});
	}
	solve();
	cout<<ans<<"\n";
	return 0;
}
