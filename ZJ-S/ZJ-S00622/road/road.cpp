#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,tem;
struct ed{
	int u,v,w;
	operator< (const ed b){
		return w<b.w;
	}
}edge[1010005];
int bc[10050];
int fa(int x){
	if(bc[x]==x) return x;
	return bc[x]=fa(bc[x]);
}
long long d(){
	long long ans=0;
	for(int i=1;i<=n+k;i++) bc[i]=i;
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++){
		fa(edge[i].u);
		if(fa(edge[i].v)!=fa(edge[i].u)){
			ans+=(long long)edge[i].w;
			bc[fa(edge[i].v)]=fa(edge[i].u);
		}
		fa(edge[i].v);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	if(k==0) printf("%lld",d());
	else{
		for(int i=1;i<=k;i++){
			scanf("%d",&tem);
			for(int j=1;j<=n;j++) {
				m++;
				edge[m].u=n+i;
				edge[m].v=j;
				scanf("%d",&edge[m].w);
			}
		}
		printf("%lld",d());
	}
	return 0;
}
