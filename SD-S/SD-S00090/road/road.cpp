#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define int long long
const int N = 1e4+5;
const int M = 1e6+5;
struct Edge{
	int u,v,w;
};
vector<Edge>edge;
int n,m,k;
int u,v,w;int a[N];
int fa[N];
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
bool pd(int x,int y){
	if(find(x)==find(y))return true;
	else return false;
}
void un(int x,int y){
	for(int i=1;i<=n;i++){
		if(fa[i]==fa[x]){
			fa[i]=fa[y];
		}
	}
	fa[x]=fa[y];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		edge.push_back({u,v,w});
	}
	for(int i=0;i<k;i++){
		int c;
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				edge.push_back({j,k,(c+a[j]+a[k])});
			}
		}
	}
	sort(edge.begin(),edge.end(),cmp);
//	for(int i=0;i<edge.size();i++){
//		printf("Edge:%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
//	}
	int sum=0;
	for(int i=0;i<edge.size();i++){
		int from=edge[i].u;
		int to=edge[i].v;
		int wi=edge[i].w;
		if(!pd(from,to)){
//			printf("FT%d %d\n",from,to);
			sum+=wi;
			un(from,to);
		}
		int o=0;
		int x=fa[1];
		for(int j=2;j<=n;j++){
			if(x!=fa[j]){
				o=1;
				break;
			}
		}
		if(o==0){
			break;
		}
//		for(int j=1;j<=n;j++){
//			printf("%d ",fa[j]);
//		}printf("\n");
	}
	printf("%lld",sum);
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

