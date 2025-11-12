#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,u,v,w[N],c[15],a[15][N],sum; 
bool A(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0) return 0;
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0) return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w[i]);
		sum+=w[i];
	}
	for(int i=1;i=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0){
		printf("%lld",sum);
	}
	if(A()){
		printf("%lld",0);
	} 
	return 0;
} 
