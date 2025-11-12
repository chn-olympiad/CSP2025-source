#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1000000+10,inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	int x,y,w;
	bool operator<(edge &_){
		return w<_.w;
	}
};
vector<edge> e,E,wk;
int n,m,K,c[15],a[15][10010],fa[10010],tot;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=tot;i++) fa[i]=i;
	sort(e.begin(),e.end());
	int cnt=0;
	for(int i=0;i<e.size();i++){
		int x=e[i].x,y=e[i].y,w=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			E.push_back(e[i]);
			cnt++;
		}
		if(cnt==tot-1) break;
	}
}
ll krus(){
	for(int i=1;i<=tot;i++) fa[i]=i;
	sort(wk.begin(),wk.end());
	ll rtn=0;
	int cnt=0;
	for(int i=0;i<wk.size();i++){
		int x=wk[i].x,y=wk[i].y,w=wk[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			rtn+=w;
			cnt++;
		}
		if(cnt==tot-1) break;
	}
	return rtn;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1,x,y,w;i<=m;i++){
		cin>>x>>y>>w;
		e.push_back({x,y,w});
	}
	tot=n;
	init();
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ll ans=inf;
	for(int i=0;i<(1<<K);i++){
		wk=E;
		tot=n;
		ll res=0;
		for(int j=0;j<K;j++){
			if((i>>j)&1){
				res+=c[j+1];
				tot++;
				for(int k=1;k<=n;k++){
					wk.push_back({tot,k,a[j+1][k]});
				}
			}
		}
		res+=krus();
		ans=min(ans,res);
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}
