#include <bits/stdc++.h>
using namespace std;

const int N=1e4+15,M=1e6+5,P=110005;
int n,m,k,u,v,w,c[15],a[15][N];
int fa[N],b[15],Use[15],g[15],tot;
long long ans;

struct edge{
	int val,u,v,id;
}f[M];

inline bool cmp(edge a1,edge a2){
	if(a1.val<a2.val)
		return true;
	else{
		if(a1.val==a2.val&&a1.id>a2.id)
			return true;
		else
			return false;
	}
}

inline int findset(int k1){
	if(fa[k1]==k1) return k1;
	return fa[k1]=findset(fa[k1]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&f[i].u,&f[i].v,&f[i].val),f[i].id=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);	
	}
	
	if(!k){
		long long ans=0;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(f+1,f+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=findset(f[i].u),fy=findset(f[i].v);
			if(fx==fy) continue;
			ans+=1LL*f[i].val;
			fa[fx]=fy;
		}
		printf("%lld\n",ans);
		return 0;	
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			f[++m].u=n+i,f[m].v=j,f[m].val=a[i][j];
			f[m].id=0;
		}
	}
	for(int i=1;i<=k;i++){
		f[++m].u=n+k+1,f[m].v=n+i,f[m].val=c[i];
		f[m].id=1;
	}
	sort(f+1,f+m+1,cmp);
	for(int i=1;i<=n+k+1;i++)
		fa[i]=i;

	for(int i=1;i<=m;i++){
	
		int x=f[i].u,y=f[i].v,w=f[i].val;
		int fx=findset(x),fy=findset(y);
		if(fx==fy) continue;

		if(x>n&&x!=n+k+1){
			if(b[x-n])
				ans+=1LL*w,Use[x-n]=1,fa[fx]=fy;
		} else{
			if(x==n+k+1){
				b[y-n]=1,g[y-n]=w;
				ans+=1LL*w;
				fa[fx]=fy;
			} else
				ans+=1LL*w,fa[fx]=fy;
		}
		
	}
	for(int i=1;i<=k;i++)
		if(!Use[i]&&g[i])
			ans-=1LL*g[i];
	printf("%lld\n",ans);
}