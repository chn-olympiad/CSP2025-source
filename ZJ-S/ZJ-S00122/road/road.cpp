#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a,ans,c[15],sum[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
	}
	ans=1<<30;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			sum[i]+=a;
		}
		sum[i]+=c[i];
		ans=min(ans,sum[i]);
	}
	printf("%d",ans);
	return 0;
}