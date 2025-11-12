#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct p{
	int u,to;
	double w;
}a[2200006];
bool v[1015];
bool cmp(p a,p b){
	return a.w<b.w;
}
int f[1105];
long double ans,ans1;
int find(int u){
	if(f[u]==u){
		return u;
	}
	return f[u]=find(f[u]);
}
void uni(int u,int v){
	int nu=find(u);
	int nv=find(v);
	f[nu]=nv;
}
int main(){
	for(int i=1;i<=1100;i++){
		f[i]=i;
	}
	freopen("road.in","r",stdin);
	freopen("roed.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lf",&a[i].u,&a[i].to,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		double x;
		scanf("%lf",&x);
		for(int j=1;j<=n;j++){
			scanf("%lf",&a[i*n-n+j+m].w);
			a[i*n-n+j+m].w+=x/2;
			a[i*n-n+j+m].u=i+n;
			a[i*n-n+j+m].to=j;
		} 
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].to)){
			continue;
		}
		uni(a[i].u,a[i].to);
		ans1+=a[i].w;
	}
	for(int i=1;i<=1100;i++){
		f[i]=i;
	}
	m+=k*n;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].to)){
			continue;
		}
		if(ans+a[i].w>ans1&&a[i].u>m-k*n){
			continue;
		}
		v[a[i].u]=v[a[i].to]=1;
		uni(a[i].u,a[i].to);
		ans+=a[i].w;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			cout<<ans1;
			return 0;
		}
	}
	cout<<(long long)min(ans,ans1);
	return 0;
}
