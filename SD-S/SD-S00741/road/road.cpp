#include<bits/stdc++.h>
#define int long long
#define first x
#define second y
using namespace std;
int n,m,k,fa[1000010],s=0,p=0;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(x);
}
pritvary_queue<pair<int,pair<int,int> > > q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push(make_pair(-w,make_pair(u,v)));
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		s+=x;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			q.push(make_pair(-y,make_pair(n+i,j)));
		}
	}
	while(!q.empty()&&p<n+k-1){
		int t=q.top().x,ui=q.top().y.x,vi=q.top().y.y;
		q.pop();
		if(find(ui)!=find(vi)){
			fa[max(ui,vi)]=min(ui,vi);
			s+=(-t);
			p++;
		}
	}
	cout<<s;
	return 0;
} 
