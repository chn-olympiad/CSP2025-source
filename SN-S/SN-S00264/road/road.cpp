#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[2000005],a[15][10005],c[15];
struct edge{
	int from,to,w;
}edg[2200005];
namespace Subtask1{//16pts
	int fa[10005];
	long long anss=0;
	inline int find(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	inline void merge(int u,int v){
		fa[find(u)]=find(v);
		return;
	}
	inline bool cmp(edge x,edge y){
		return x.w<y.w;
	}
	signed main(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(edg+1,edg+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(edg[i].from)==find(edg[i].to)){
				continue;
			}
			merge(edg[i].from,edg[i].to);
			anss+=edg[i].w;
		}
		cout<<anss<<endl;
		return 0;
	}
};
namespace Subtask2{
	int fa[10005];
	long long anss=0,tot=0;
	inline int find(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	inline void merge(int u,int v){
		fa[find(u)]=find(v);
		return;
	}
	inline bool cmp(edge x,edge y){
		return x.w<y.w;
	}
	signed main(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		tot=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					merge(i,j);
				}
				else{
					edg[++tot].from=i,edg[tot].to=j,edg[tot].w=a[i][j];
				}
			}
		}
		sort(edg+1,edg+1+tot,cmp);
		for(int i=1;i<=tot;i++){
			if(find(edg[i].from)==find(edg[i].to)){
				continue;
			}
			merge(edg[i].from,edg[i].to);
			anss+=edg[i].w;
		}
		cout<<anss<<endl;
		return 0;
	}
};
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 1 3 0 4
*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edg[i].from>>edg[i].to>>edg[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		Subtask1::main();
		return 0;
	}
	Subtask2::main();
	return 0;
}
