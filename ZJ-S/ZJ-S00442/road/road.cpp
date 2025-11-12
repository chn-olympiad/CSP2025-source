#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,m,k,x,y,z,lin[100],tot,j,fa[10100],ans,bian,ans1[100],v1[100],v2[100];
struct no{
	ll x,y,z;
}a[1200100];
bool cmp(no xx,no yy){
	if (xx.z==yy.z) return xx.x<yy.x;
	return xx.z<yy.z;
}
ll find(ll x){
	if (fa[x]==-1) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		a[++tot].x=x;a[tot].y=y;a[tot].z=z;
	}
	for (i=1;i<=k;i++){
		x=n+(i-1)*2+1;y=n+(i-1)*2+2;
		lin[x-n]=y;lin[y-n]=x;
		scanf("%lld",&z);
		a[++tot].x=x;a[tot].y=y;a[tot].z=z;
		for (j=1;j<=n;j++){
			scanf("%lld",&z);
			a[++tot].x=x;a[tot].y=j;a[tot].z=z;
			a[++tot].x=y;a[tot].y=j;a[tot].z=z;
		}
	}
	sort(a+1,a+1+tot,cmp);
	for (i=1;i<=n+k*2;i++) fa[i]=-1;
	for (i=1;i<=tot;i++){
		ll fx=find(a[i].x),fy=find(a[i].y);
		if (fx!=fy){
			if (a[i].x>n){
				if (a[i].y>n){
					ans+=a[i].z;
					fa[fx]=fy;bian++;
					ans1[a[i].x-n]+=a[i].z;
					v2[a[i].x-n]=1;
				}
				else{
					if (!v1[lin[a[i].x-n]-n]&&v1[a[i].x-n]) continue;
					else{
						ll fxx=find(lin[a[i].x-n]);
						if (fxx==fy) continue;
						ans+=a[i].z;
						fa[fx]=fy;bian++;
						ans1[a[i].x-n]+=a[i].z;
						v1[a[i].x-n]=1;
					}
				}
			}
			else{
				fa[fx]=fy;bian++;
				ans+=a[i].z;
			}
		}
		if (bian==n+2*k-1) break;
	}
	for (i=1;i<=2*k;i+=2)
		if (v1[i]==0||v1[i+1]==0||v2[i]==0)
			ans-=ans1[i]+ans1[i+1];
	printf("%lld\n",ans);
	return 0;
}