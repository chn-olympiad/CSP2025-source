#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct EDGE{
	int u,v,w;
	bool operator<(const EDGE&b)const{
		return w<b.w;
	}
};
vector<EDGE> s;
int c[N],con[N];
int fa[N],sz[N];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
} 
int find(int u,int pre){
	
	if(fa[u]==u) return u;
	return find(fa[u],u);
} 
int connect(int u,int v){
	int rt=find(v,-1);
	fa[u]=rt;
	sz[rt]+=sz[u];
	return sz[rt];
}
int ans=0,wc[N];
int main(){
	//对于特殊性质A 
	//最小生成树 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//eg3ans:504898585

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s.push_back({u,v,w});
		s.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>wc[j];
			
//			s.push_back({n+i,j,w});
//			s.push_back({j,n+i,w});
			
		}
		for(int i1=1;i1<=n;i1++){
			for(int j1=1;j1<=n;j1++){
				if(i1==j1) continue;
				s.push_back({i1,j1,wc[i1]+wc[j1]+c[i]});
			}
		}
	}

	init(n); 
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		ans+=w;
		int ndn=connect(u,v);
		if(ndn>=n){
			cout<<ans;
			return 0;
		} 
	}
//	cout<<"???";
	return 0;
}
