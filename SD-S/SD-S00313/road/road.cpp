#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define int long long

const int N=1e4+10;
int n,m,k,s[N],ans=9e18;
bool vis[N];
struct dlNode{
	int u,v,w;
};
vector<dlNode> dl,vvv;
struct cjhNode{
	int c,a[N];
}cj[20];
void init(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++){
		s[i]=i;
	}
}
int find(int x){
	if(x!=s[x]){
		s[x]=find(s[x]);
	}
	return s[x];
}
bool cmp(dlNode a,dlNode b){
	return a.w<b.w;
}
int kurskal(){
	init();
//	sort(dl.begin()+1,dl.end(),cmp);
	vector<dlNode> vvvv;
	vvvv.clear();
	for(int i=1;i<dl.size();i++)vvvv.push_back(dl[i]);
	for(int i=0;i<vvv.size();i++)vvvv.push_back(vvv[i]);
	sort(vvvv.begin(),vvvv.end(),cmp);
	int tans=0,cnt=0;
	for(int i=0;i<vvvv.size();i++){
		auto fu=find(vvvv[i].u);
		auto fv=find(vvvv[i].v);
		if(fu==fv)continue;
		tans+=vvvv[i].w;
		s[fu]=s[fv];
		if(!vis[fu]&&fu<=n)cnt++;
		if(!vis[fv]&&fv<=n)cnt++;
		vis[fu]++;
		vis[fv]++;
//		cerr<<fu<<' '<<fv<<' '<<vvvv[i].w<<'\n';
		if(cnt==n){
			break;
		}
	}
//	cerr<<tans<<' '<<cnt<<' ';
	if(cnt<n)return 1e18;
	return tans;
}
void dfs(int step,vector<dlNode> vv,int sumxj){
	if(step>k){
//		cerr<<"OMG!\n";
		int lenvv=vv.size();
		for(int i=0;i<lenvv;i++)vvv.push_back(vv[i]);
//		for(int i=1;i<dl.size();i++)cerr<<dl[i].u<<' '<<dl[i].v<<' '<<dl[i].w<<'\n';
		ans=min(ans,kurskal()+sumxj);
//		cerr<<sumxj<<'\n';
		for(int i=0;i<lenvv;i++)vvv.pop_back();
//		cerr<<"ANS: "<<ans<<'\n';
		return;
	}
	dfs(step+1,vv,sumxj);
	for(int i=1;i<=n;i++){
		dlNode x={n+step,i,cj[step].a[i]};
		vv.push_back(x);
	}
	dfs(step+1,vv,sumxj+cj[step].c);
	for(int i=1;i<=n;i++){
		vv.pop_back();
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	cin>>n>>m>>k;
	dl.push_back({-1,-1,-1});
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dl.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cj[i].c;
		for(int j=1;j<=n;j++){
			cin>>cj[i].a[j];
		}
	}
	dfs(1,{},0);
	cout<<ans;

	return 0;
}

