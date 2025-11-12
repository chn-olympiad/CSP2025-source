#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[10015],cnt,n,ans=1e18,sum,m,k,cs,vi[15],fc[15],vg[15][10005],vis[15],f=0;
vector<pair<int,pair<int,int>>>ls;
vector<int>jl;
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
int solve(){
	sum=0;vector<pair<int,pair<int,int>>>my=ls;
	//cout<<1<<endl;
	for(int& it:jl){
		sum+=vi[it];
		for(int i=1;i<=n;i++){
			my.push_back({vg[it][i],{i,n+it}});
		}
	}
	sort(my.begin(),my.end());cnt=1;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++)vis[i]=0;
	//cout<<2<<endl;
	for(auto& it:my){
		if(sum>ans)return 1e18;
		if(cnt==n)continue;
		int u=it.second.first,v=it.second.second;
		if(find(u)!=find(v)){
			if(u>n&&vis[u-n]==0)vis[u-n]=1;
			else if(v>n&&vis[v-n]==0)vis[v-n]=1;
			else cnt++;
			sum+=it.first;
			fa[find(u)]=find(v);
		}
	}
	//cout<<cnt<<' '<<sum<<endl;
	return sum;
}
void dfs(int x){
	//cout<<x<<endl;
	if(x==k+1){
		ans=min(ans,solve());
		return;
	}
	dfs(x+1);
	if(!fc[x]){
		jl.push_back(x);
		dfs(x+1);
		jl.pop_back();
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		ls.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++){
		cin>>vi[i];for(int j=1;j<=n;j++){
			int x;cin>>x;
			vg[i][j]=x;
		}
		f|=vi[i];
	}
	if(!f){
		for(int i=1;i<=k;i++){
			jl.push_back(i);
		}
		ans=min(ans,solve());
	}
	else{
		cs=solve();
		for(int i=1;i<=k;i++){
			jl.push_back(i);
			if(solve()>cs)fc[i]=1;
			jl.pop_back();
		}
		dfs(1);
	}
	cout<<ans;
	return 0;
}