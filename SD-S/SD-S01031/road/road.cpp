#include<bits/stdc++.h>
using namespace std;

const int N=200010;
int n,m,k,in[N],c,fee[10][N];
long long ans;
struct node{
	int u,v;
	long long w;
}e[N];
bool cmp(node _,node __){
	return _.w>__.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		in[e[i].u]++;in[e[i].v]++;
		ans+=e[i].w;
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&fee[i][j]);
		}
	}

//	for(int i=1;i<=n;i++){
//		cout<<in[i]<<" ";
//	}
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		long long u=e[i].u,v=e[i].v,w=e[i].w;
		if(in[u]>2||in[v]>2&&(in[u]>1&&in[v]>1)){
//			cout<<u<<" "<<v<<" "<<w<<"\n";
			ans-=w;
			in[u]--;in[v]--;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 5 2
1 4 6
2 3 7
4 2 5
4 3 4
1 2 3
1 1 8 2 4
100 1 3 2 4
*/
