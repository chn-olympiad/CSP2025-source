#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,i,a;
}x[100100],y[100100],z[100100];
bool cmp(node a,node b){
	return a.a<b.a;
}
int T,e,a[100100],b[100100],c[100100];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		scanf("%lld",&e);
		int ans=0,n=0,m=0,r=0;
		for(int i=1;i<=e;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x[++n].a=min(a[i]-b[i],a[i]-c[i]);
				x[n].i=i;
				ans+=a[i];
			}else if(b[i]>=c[i]){
				y[++m].a=min(b[i]-a[i],b[i]-c[i]);
				y[m].i=i;
				ans+=b[i];
			}else{
				z[++r].a=min(c[i]-a[i],c[i]-b[i]);
				z[r].i=i;
				ans+=c[i];
			}
		}
		if(n>e/2){
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=n-e/2;i++){
				ans-=x[i].a;
			}
		}
		if(m>e/2){
			sort(y+1,y+1+m,cmp);
			for(int i=1;i<=m-e/2;i++){
				ans-=y[i].a;
			}
		}
		if(r>e/2){
			sort(z+1,z+1+r,cmp);
			for(int i=1;i<=r-e/2;i++){
				ans-=z[i].a;
			}
		}printf("%lld\n",ans);
	}
	return 0;
}
//%%lsj %%hzh %%%%%%%%%%%%