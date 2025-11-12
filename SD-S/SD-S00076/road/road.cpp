#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[11000],ans;
bool b[11000];
struct node{
	long long u,v,w;
}a[1001000];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int k){
	if(fa[k]==k)return k;
	return fa[k]=find(fa[k]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		int x;
		for(int i=0;i<=n;i++)scanf("%d",&x);
	}
	int tot=0,now=0;
	while(tot!=n-1){
		now++;
		int x=a[now].u,y=a[now].v;
		if(find(x)==find(y))continue;
		else{
			ans+=a[now].w;
			tot++;
			fa[x]=find(fa[y]);
		}
	}
	printf("%d",ans);
	return 0;
}//16pts
