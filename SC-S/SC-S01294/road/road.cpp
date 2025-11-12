#include<bits/stdc++.h>
using namespace std;
long long ans=0,tot=0,top=0;
long long n,m,k;
long long fa[10050];
long long anss[1000050];
struct node{
	long long u,v,w;
}bian[1000050];
bool cmp(node a,node b){
	return a.w<b.w;
}
long long find(long long x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void kru(){
	ans=0,tot=0;
	for(long long i=1;i<=n;i++)fa[i]=i;
	sort(bian+1,bian+m+1,cmp);
	for(long long i=1;i<=m;i++){
		long long a=bian[i].u;
		long long b=bian[i].v;
		if(find(a)==find(b))break;
		fa[find(b)]=find(a);
		ans+=bian[i].w;
		tot++;		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&bian[i].u,&bian[i].v,&bian[i].w);
	}	
	if(k==0){
		kru();
		printf("%lld",ans);
		return 0;
	}
	int top=m;
	for(long long i=1;i<=k;i++){
		long long val;scanf("%lld",&val);
		for(long long j=1;j<=n;j++){
			long long er;scanf("%lld",&er);
			bian[++top].u=i+n;
			bian[top].v=j;
			bian[top].w=er;
		}
	}
	kru();
	printf("%lld",ans);	
	return 0;
}