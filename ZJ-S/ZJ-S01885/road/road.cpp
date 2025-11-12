#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[11],b[11],i,j,ans,sum,res,cnt,t,f[200001],p;
struct Node{
	long long x,y,w;
}a[1200001];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
long long find(long long x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(long long x,long long y){
	f[find(y)]=find(x);
	return;
}
void solve(long long s){
	t=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=cnt;i++){
		if(ans>=res) return;
		if(t==n+sum-1) break;
		if(find(a[i].x)==find(a[i].y)||(a[i].x>n&&b[a[i].x-n]==0)||(a[i].y>n&&b[a[i].y-n]==0)) continue;
		ans+=a[i].w,t++;
		merge(a[i].x,a[i].y);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
	for(i=1,cnt=m;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]>0) p=1;
		for(j=1;j<=n;j++) scanf("%lld",&a[++cnt].w),a[cnt].x=j,a[cnt].y=i+n;
	}
	sort(a+1,a+1+cnt,cmp);
	for(i=0,res=1e17;i<(1<<k);i++){
		if(p==0) i=(1<<k)-1;
		for(ans=0,j=1,sum=0;j<=k;j++){
			if((i>>(j-1))&1) ans+=c[j],sum++,b[j]=1;
		}
		if(ans<res) solve(i);
		res=min(res,ans);
		for(j=1;j<=k;j++) b[j]=0;
	}
	printf("%lld",res);
	return 0;
}