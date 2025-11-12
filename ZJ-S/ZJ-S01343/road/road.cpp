#include<bits/stdc++.h>
using namespace std;
const long long M=1e6+50;
const long long N=1e4+50;
struct r{
	long long u,v,w;
}b[M];
long long n,m,k,ans,ffa[N],c[15][N],e[15];
vector<pair<long long,long long> >a[N];
long long find(long long x){
	if(ffa[x]==x)
	return x;
	return ffa[x]=find(ffa[x]);
}
bool cmp(r x,r y){
	return x.w<y.w;
}
void solve1(){
	for(int i=1;i<=n;i++){
		ffa[i]=i;
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(b[i].u)!=find(b[i].v)){
			ans+=b[i].w;
			ffa[find(b[i].u)]=find(b[i].v);
		}
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&e[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
//	if(k==0){
		solve1();
//	}
}
