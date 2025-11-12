#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
};
vector<edge>e;
int fa[100100];
void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool flaga=1;
	init();
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
		e.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(c!=0||x!=0){
				flaga=0;
			}
			e.push_back({n+i,j,x});
			e.push_back({j,n+i,x+c});
		}
	}
	if(flaga){
		cout<<0;
		return 0;
	}
	sort(e.begin(),e.end(),cmp);
	int cnt=0;
	long long sum=0;
	for(int i=0;i<e.size();i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			sum+=e[i].w;
			cnt++;
		}
		if(cnt==n+k-1){
			break;
		}
	}
	cout<<sum;
	return 0;
}

