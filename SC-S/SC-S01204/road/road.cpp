#include<bits/stdc++.h>
//#define ll long long 

using namespace std;
int n,m,k,fa[1000005];
struct edges{
	int u,v,w;
}edge[1000005];
bool cmp(edges a,edges b){
	return a.w<b.w;
}
bool check(){
	int se=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i)se++;
		if(se>=2)return 0;
	}
	return 1;
}
int find(int i){
	if(fa[i]==i)return i;
	return find(fa[i]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int sum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	
	sort(edge,edge+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		sum+=edge[i].w;
		if(fa[edge[i].u]!=edge[i].u)fa[edge[i].u]=find(edge[i].v);
		else fa[edge[i].v]=find(edge[i].u);
		if(check())break;
	}
//	for(int i=0;i<m;i++){
//		printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
//	}
//	for(int i=1;i<=n;i++){
//		cout<<fa[i]<<" ";
//	}
	printf("%d\n",sum);
	return 0;
} 
//114514,114,514 mr.beast

//4 4 2
// 1 4 6
// 2 3 7
// 4 2 5
// 4 3 4