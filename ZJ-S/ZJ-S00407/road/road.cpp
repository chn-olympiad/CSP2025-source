#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,c[10005],a[15][10005],fa[10005];
ll ans;
struct Info{
	int x,y,z;
	bool operator < (const Info A)const{
		return A.z>z;
	}
}e[2000005];
int f(int x){
	if(fa[x]==x)return x;
	fa[x]=f(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(k==0){
		sort(e+1,e+m+1);
		for(int i=1;i<=m;i++){
			if(f(e[i].x)!=f(e[i].y)){
				ans+=e[i].z;
				fa[f(e[i].x)]=f(e[i].y);
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
