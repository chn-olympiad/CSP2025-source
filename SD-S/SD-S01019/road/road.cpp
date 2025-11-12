#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
};
int n,m,k;
const int xx=1e6+6;
const int xxx=1e4+4;
vector<node> kul;
int w[xx],ww[xx];
bool pd[xxx];
bool pdd[xxx];
bool cmp(node a,node b){
	return a.w<b.w;
}
vector<pair<int,int> > G[xx];
int fa[xxx],rk[xxx];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return ;
	if(rk[x]>rk[y]) fa[y]=x;
	else if(rk[x]<rk[y]) fa[x]=y;
	else{
		fa[x]=y;
		rk[y]++;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rk[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}	
	int sum=0;
	for(int i=1;i<=k;i++){
		int w1;
		cin>>w1;
		for(int j=1;j<=n;j++){
			int w2;
			cin>>w2;
			w[j]=w1+w2;
			ww[j]=w2;
		}
		int di=1;
		for(auto &edge:G[i]){
			if(w[edge.first]>edge.second){
				kul.push_back({i,edge.first,edge.second});
				pd[edge.first]=true;
			}else{
				if(!pdd[i]){
					sum=w[i]-ww[i];
				}
				kul.push_back({i,edge.first,min(w[edge.first],edge.second)});
				pd[edge.first]=true;
				pd[i]=true;
				pdd[i]=true;
			}
		}
		for(int j=1;j<=n;j++){
			if(!pd[j]){
				kul.push_back({i,j,w[j]});
			}
		}
	}
	for(int i=k+1;i<=n;i++){
		for(auto &edge:G[i]){
			kul.push_back({i,edge.first,edge.second});
		}
	}
	sort(kul.begin(),kul.end(),cmp);
	for(auto edge:kul){
		if(find(edge.u)!=find(edge.v)){
			merge(edge.u,edge.v);
			sum+=edge.w;
		}
	}
	cout<<sum<<"\n";
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
