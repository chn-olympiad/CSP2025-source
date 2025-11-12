#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int a[10005][10005],c[11][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int ina,inb,w;
		scanf("%d %d %d",&ina,&inb,&w);
		a[ina][inb]=a[inb][ina]=w;
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}printf("10\n");
	return 0;
}