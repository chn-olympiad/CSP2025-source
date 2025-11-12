#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
const int M=2000006;
int n,m,k;
struct Side{
	int u,v,w;
}sd[M];
int c[11];
int a[11][N];
int p0[11];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		return true;
	}else{
		return false;
	}
}
bool cmp(Side x,Side y){
	return x.w<y.w;
}
namespace subtaskA{//O(mlogm) 
void solve(){//io用时一秒多？ 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j!=p0[i]){
				sd[++m]=(Side){p0[i],j,a[i][j]};
			}
		}
	}
//	printf("sides:%d\n",m);
	sort(sd+1,sd+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(merge(sd[i].u,sd[i].v)){
			ans+=sd[i].w;
		}
	}
	printf("%lld\n",ans);
} 

}
namespace subtaskKlt5{//O(2^5*mlogm) 14s?!
void solve(){
	int b=1;
	for(int i=1;i<=k;i++) b=b*2;
	ll ans=1e18;
	for(int p=0;p<b;p++){
//		printf("p=%d\n",p); 
		ll res=0;
		int tn=n,tm=m;
		for(int i=1;i<=k;i++){
			if((p>>(i-1))&1){
//				printf("usd village %d\n",i); 
				tn++;
				res+=c[i];
				for(int j=1;j<=n;j++){
					sd[++tm]=(Side){tn,j,a[i][j]};
				}
			}
		}
		sort(sd+1,sd+tm+1,cmp);
		for(int i=1;i<=tn;i++) fa[i]=i;
		for(int i=1;i<=tm;i++){
			if(merge(sd[i].u,sd[i].v)){
//				printf("connect %d %d at the cost of %d\n",sd[i].u,sd[i].v,sd[i].w); 
				res+=sd[i].w;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&sd[i].u,&sd[i].v,&sd[i].w); 
	}
	bool fA=true; 
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) fA=false; 
		bool ext0=false;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0){
				ext0=true;	
				p0[i]=j;
			}
		}
		if(!ext0) fA=false;
	}
	if(fA){
		subtaskA::solve();
	}else{
		subtaskKlt5::solve();
	}
	return 0;
}
