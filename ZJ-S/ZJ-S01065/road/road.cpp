#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ans += w;
	}
	printf("%d",ans);
	return 0;
}
