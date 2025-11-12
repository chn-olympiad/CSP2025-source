#include<bits/stdc++.h>
using namespace std;
long long n,m,k,w[1010001],u[1010001],v[1001010],c[1001010],a[10010][20],sum1,sum2,minn=1e18;
void f(int mid){
	sum2=c[mid];
	for(int i=1;i<=n;i++){
		sum2+=a[mid][i];
	}
	minn=min(minn,sum2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld",&u[i]);
		scanf("%lld",&v[i]);
		scanf("%lld",&w[i]);
		sum1+=w[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		f(i);
	}
	cout<<min(sum1,minn);
	return 0;
} 
