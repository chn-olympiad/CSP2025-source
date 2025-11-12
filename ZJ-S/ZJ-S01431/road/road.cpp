#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1000005;
const int INF=0x3f3f3f3f;
struct Edge{
	int u,v;
	ll w;
}e[N],b[N*2];
ll a[15][10005];
ll c[N];
int p[N];
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
bool chk[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	ll mx=0;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,mx=max(mx,e[i].w);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(e+1,e+m+1,cmp);
	vector<Edge> vec;
	for(int i=1;i<=n;i++) p[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		ll w=e[i].w;
		int px=find(x),py=find(y);
		if(px!=py){
			p[px]=py;
			ans+=w;
			vec.push_back({x,y,w});
		}
	}
	for(int s=1;s<=k;s++){
		int tot=0;
		for(int t=1;t<=n;t++){
			if(a[s][t]<=mx) b[++tot]={s+n,t,a[s][t]};
		}
		for(auto t:vec) b[++tot]=t;
		sort(b+1,b+tot+1,cmp);
		for(int j=1;j<=n+k;j++) p[j]=j;
		ll res=0;
		for(int j=1;j<=tot;j++){
			int x=b[j].u,y=b[j].v;
			ll w=b[j].w;
			int px=find(x),py=find(y);
			if(px!=py){
				p[px]=py;
				res+=w;
				if(res+c[s]>ans) break;
			}
		}
		if(res+c[s]<=ans) chk[s]=1;
	}
	for(int s=0;s<1<<k;s++){
		ll sum=0;
		int tot=0;
		bool ok=1;
		for(int j=0;j<k;j++){
			if(s>>j&1){
				if(!chk[j+1]){
					ok=0;
					break;
				}
				sum+=c[j+1];
				for(int t=1;t<=n;t++){
					if(a[j+1][t]<=mx) b[++tot]={j+n+1,t,a[j+1][t]};
				}
			}
		}
		if(!ok) continue;
		for(auto t:vec) b[++tot]=t;
		sort(b+1,b+tot+1,cmp);
		for(int j=1;j<=n+k;j++) p[j]=j;
		ll res=0;
		for(int j=1;j<=tot;j++){
			int x=b[j].u,y=b[j].v;
			ll w=b[j].w;
			int px=find(x),py=find(y);
			if(px!=py){
				p[px]=py;
				res+=w;
				if(res+sum>ans) break;
			}
		}
		ans=min(ans,res+sum);
	}
	cout<<ans<<"\n";
	return 0;
}

