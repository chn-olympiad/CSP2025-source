#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
long long n,m,k,f[M],q[M],z[M],c[M],a[100000][100000],x[M]={INT_MAX},cx[M]={INT_MAX},ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i],&z[i],&f[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c[i]);
		for(int j=1;j<=n;j++){
			scanf("&d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		if(q[i]==i||z[i]==i){
			x[i]=min(x[i],f[i]);
		}else{
			x[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		ans+=x[i];
		if(x[i]==0){
			x[i]=INT_MAX;
			for(int j=1;j<=k;j++){
				for(int pp=1;pp<=k;pp++){
					if(pp!=i){
						cx[i]=min(cx[i],a[j][pp]);
					}
				}
				x[i]=min(x[i],cx[i]+c[j]+a[j][i]);
			}
			ans+=x[i];
		}
	}
	cout<<ans;
	return 0;
}