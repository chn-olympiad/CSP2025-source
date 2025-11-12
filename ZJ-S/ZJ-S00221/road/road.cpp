#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[1000010],u,v,w,sum;
struct edge{int u,v,id;};
operator < (edge a,edge b){return a.id<b.id;}
map<edge,int>a;
edge f_a[1000010];
int d[2000010];
int countryside[10][10010];
int find(int x){return fa[x]=((fa[x]==x)?x:find(fa[x]));}
void uni(int x,int y){fa[y]=x;}
void start(int n){for(int i=0;i<=n;i++)fa[i]=i;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	start(n);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[(edge){u,v,i}]=w;
		d[i]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>countryside[i][j];
		}
	}
//	cout<<coutntryside[i-u+v][j-v+u]+w;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		if(find(f_a[w].u)!=find(f_a[w].v)){
			sum+=w;uni(f_a[w].u,f_a[w].v);
		}
	}
	cout<<w;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/