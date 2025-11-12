#include <bits/stdc++.h>
const int N=1e4+5,M=1e6+5;
using namespace std;
struct Edge{
	int u,v,w;
	bool operator <(const Edge other)const{
		return w<other.w;
	}
};
int n,m,k,ans=0;
Edge edges[M];
int idx=0;
int val[N];

int fa[N];
int find(int k){
	if(fa[k]==k) return k;
	return fa[k]=find(fa[k]);
}
void unionn(int a,int b){
	int ra=find(a),rb=find(b);
	if(ra==rb) return ;
	fa[ra]=rb;
}

void kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edges+1,edges+idx+1);
	for(int i=1;i<=idx;i++){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;
		unionn(u,v);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[++idx]={u,v,w};
	}
	if(k){
		for(int i=1;i<=k;i++){
			int tmp;
			cin>>tmp;
			memset(val,0,sizeof(val));
			for(int j=1;j<=n;j++){
				cin>>val[j];
				for(int l=1;l<j;l++){
					edges[++idx]={l,j,val[j]+val[l]};
				}
			}
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/
