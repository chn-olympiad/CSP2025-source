#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,vv,f[10010],cnt=1;
struct Node{
	long long u,v,w;
}a[10010];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
long long fa(long long x){
	if(f[x]=x){
		return f[x];
	}
	return f[x]=fa(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&vv);
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(fa(a[i].u)!=fa(a[i].v)){
			if(a[i].u>=a[i].v){
				f[a[i].u]=a[i].v;
			}
			else{
				f[a[i].v]=a[i].u;
			}
			ans+=a[i].w;
			cnt++;
			if(cnt==n){
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
