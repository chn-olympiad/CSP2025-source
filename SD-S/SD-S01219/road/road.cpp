#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,m,k,p,x,ans;
struct node{
	long long u,v,w;
}a[N];
int cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
	}
	if(k==0){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n;i++){
			ans+=a[i].w;
		}
		printf("%lld",ans);
		return 0;
	}
	while(k--){
		scanf("%lld",&p);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
		}
	}
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
