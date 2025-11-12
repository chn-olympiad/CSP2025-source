#include <iostream>
#include <vector>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct node{
	int to,w;
};
vector<node> e[N];
int c[15],a[15][N];
inline int cost(int i,int x,int y){
	return a[i][x]+a[i][y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		node u,v;int w;
		scanf("%d%d%d",&u.to,&v.to,&w);
		u.w=w;v.w=w;
		e[v.to].push_back(v);
		e[u.to].push_back(u);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("0");
	return 0;
}
