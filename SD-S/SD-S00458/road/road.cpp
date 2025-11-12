#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int N=1e4+100,M=1e6+100;
ll n,m,k,a[20][N],c[20],tot=0,f[N],cnt=0,ans=0,kz=0;
struct E{
	ll u,v,w;
}e[M];
bool cmp(E A,E B){
	return A.w<B.w;
}
int findf(int x){
	if(f[x]==x)return x;
	return f[x]=findf(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	tot=m;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	bool fg=0;
	for(int i=1;i<=k;i++){
		bool fl=1;
		scanf("%lld",&c[i]);
		kz+=c[i];
		if(c[i]!=0)fl=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]!=0)fl=0;
			e[++tot].u=i+n;
			e[tot].v=j;
			e[tot].w=a[i][j];
		}
		if(fl==1){
			fg=1;
		}
	}
	if(fg==1){
		cout<<0;
		return 0;
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		f[i]=i;
	}
	for(int i=1;i<=tot;i++){
		int a=e[i].u,b=e[i].v;
		int fa=findf(a),fb=findf(b);
		if(fa!=fb){
			cnt++;
			ans+=e[i].w;
			f[fa]=fb;
			if(cnt==n+k-1){
				cout<<ans+kz;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 3 1 
1 3 8 
2 3 4 
1 2 5 
0 0 0 0 
*/
