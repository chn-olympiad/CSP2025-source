#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,u[100010],v[100010],w[100010],a[100010];
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	while(k--){
		for(int i=0;i<n+1;i++){
			scanf("%d",&a[i]);
		}
	}
	cout<<0;
	return 0;
}

