#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,c[N],a[15][N],fa[N],ans;
struct node{
	int u,v,w;
}edge[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int findf(int x){
	if(fa[x]==x)return x;
	return fa[x]=findf(fa[x]);
}
void kru(){
	for(int i=1;i<=m;i++){
		int x=edge[i].u,y=edge[i].v;
		if(findf(x)!=findf(y)){
			fa[x]=y;
			ans+=edge[i].w;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<j;k++){
				edge[++m].u=j;
				edge[m].v=k;
				edge[m].w=a[i][j]+a[i][k];
			}
		}
	}
	sort(edge+1,edge+m+1,cmp);
	kru();
//	for(int i=1;i<=m;i++){
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl; 
//	}
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
