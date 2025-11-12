#include<bits/stdc++.h>
#define ll long long
#define N 10010
#define M 1000010
using namespace std;
int n,m,k;
struct T{
	int u,v;ll w;
}a[M];
bool flag[N];
bool cmp(T x,T y){
	return x.w<y.w;
}
int F[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	ll ans=0,p=0;
	for(int j=1,i=1;j<n;j++){
		while(flag[a[i].u]&&flag[a[i].v]) i++;
		ans+=a[i].w;
		flag[a[i].u]=1;flag[a[i].v]=1;
	}
	printf("%lld\n",ans);
	return 0;
}