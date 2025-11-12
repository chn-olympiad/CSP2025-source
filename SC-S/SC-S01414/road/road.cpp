#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
	bool operator < (const edge &B)const{
		return w<B.w;
	}
};
int fa[100100],n,k;
int fd(int u){
	return (fa[u]==u?u:fa[u]=fd(fa[u]));
}
void uni(int u,int v){
	u=fd(u),v=fd(v);
	fa[v]=u;
}
//priority_queue<edge> a;
int kruskal(vector<edge> &b,int sz,bool opt){
	sort(b.begin(),b.end());
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int ltk=sz-1,ans=0;
	if(opt){
		vector<edge> tp;
		for(auto t:b){
			int u=t.u,v=t.v;
			if(fd(u)!=fd(v)){
				uni(u,v);
				tp.push_back(t);
				ans+=t.w;ltk--;
			}
			if(!ltk)break;	
		}
		b=tp;
	}else{
		for(auto t:b){
			int u=t.u,v=t.v;
			if(fd(u)!=fd(v)){
				uni(u,v);
				ans+=t.w;ltk--;
			}
			if(!ltk)break;	
		}
	}
	return ans;
}
int m,ans;
vector<edge> vil[15];
int c[15];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		vil[0].push_back({u,v,w});
	}
	ans=kruskal(vil[0],n,1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			vil[i].push_back({n+i,j,w});
		}
	}
	for(int i=1;i<(1<<k);i++){
		int tmp=0,sz=n;
		vector<edge>vec=vil[0];
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				tmp+=c[j];sz++;
				for(auto v:vil[j]){
					vec.push_back(v);
				}
			}
		}
		tmp+=kruskal(vec,sz,0);
		ans=min(ans,tmp);
	}
	cout<<ans;
	return 0;
}