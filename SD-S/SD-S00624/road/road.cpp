#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e4+5,M=1e6+5;
int n,m,fa[N],k,c[15][N],ans;
struct T{
	int u,v,w;
}a[M];

bool cmp(T x,T y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void K(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv){
			fa[fv]=fu;
			ans+=a[i].w;
			cnt++;
		}
		if(cnt==n-1) return;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	K();
	if(!k){
		printf("%lld",ans);
		return 0;
	}
	int mi=1e18;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		int sum=c[i][0];
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			sum+=c[i][j];
		}
		mi=min(mi,sum);
	}
	printf("%lld",min(ans,mi));
	return 0;
}//Ren5Jie4Di4Ling5%
