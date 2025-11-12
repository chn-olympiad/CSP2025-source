#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],c[20],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		int tot=0;
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			tot+=x;
		}
		ans=min(ans,tot);
	}
	printf("%d",ans);
	return 0;
}
