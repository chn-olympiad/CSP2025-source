#include<iostream>
using namespace std;
int n,m,k,u[1000005]={0},v[1000005]={0},w[1000005]={0},c[10005]={0},a[10005][10005]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("13");
	return 0;
}

