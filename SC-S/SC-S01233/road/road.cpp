#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int fa[N];
struct node{
	int u,v,w;
	bool operator>(node x)const{
		return w>x.w;
	}
};
priority_queue<node,vector<node>,greater<node> >q; 
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int getfa(int x){return (fa[x]==x?x:getfa(x));}
void merge(int x,int y){
	int xf=getfa(x);
	int yf=getfa(y);
	fa[xf]=yf;
}
int kruskal(){
	int ans=0;
	while(!q.empty()){
		int u=q.top().u,v=q.top().v,w=q.top().w;q.pop();
		if(getfa(u)!=getfa(v)){
			merge(u,v);
			ans+=w;
		}
	}
	return ans;
}
int c[15],a[15][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	int maxc=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];maxc=max(maxc,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(maxc==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				q.push({n+i,j,a[i][j]});
			}
		}
		cout<<kruskal();
	}
	else{
		cout<<kruskal();
	}
	return 0;
}
