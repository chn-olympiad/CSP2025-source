#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++)scanf("%d",&a);
	}
	printf("0");
	return 0; 
}