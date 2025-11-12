#include<iostream>//CSP-S T2
#include<cstdio>//16
#include<algorithm>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,c[K],a[K][N];
struct ed{
	int u,v,w;
}e[M];
bool cmp(ed x,ed y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	sort(e+1,e+1+n,cmp);
	long long ans=0;
	for(int i=1;i<n;i++){
		ans+=e[i].w;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
