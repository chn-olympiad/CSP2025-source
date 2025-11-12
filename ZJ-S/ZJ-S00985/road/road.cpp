#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[12005],c[15],a[15][10005],flag[15],cnt,ans,sum,idx,res,f,sss;
struct node{
	int u,v,w;
}e[1200005],g[1200005];
bool cmp(node p,node q){
	return p.w<q.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int x){
	cnt=0,ans=0;
	for(int i=1;i<=m;i++)g[i].u=e[i].u,g[i].v=e[i].v,g[i].w=e[i].w;
	if(x){
		for(int i=1;i<=n;i++){
			g[++sum].u=x;
			g[sum].v=i;
			g[sum].w=a[x-n][i];
		}
	}
	sort(g+1,g+sum+1,cmp);
	for(int i=1;i<=n+1;i++)fa[i]=i;
	for(int i=1;i<=sum;i++){
		int fx=find(g[i].u),fy=find(g[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		cnt++;
		ans+=g[i].w;
		//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
		if(cnt==res)break;
	}	
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(!c[i])sss++;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(sss==k){
		cnt=0,ans=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m].w=a[i][j];
				e[m].u=i+n,e[m].v=j;
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy)continue;
			fa[fx]=fy;
			cnt++;
			ans+=e[i].w;
			if(cnt==n+k-1)break;
		}		
		cout<<ans;
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	sum=m;
	res=n-1;
	idx=kruskal(0);
	for(int i=1;i<=k;i++){
		sum=m;
		res=n;
		if(idx-kruskal(i+n)>=c[i])flag[i]=1;
	}
	sum=m;
	ans=0;
	for(int i=1;i<=k;i++){
		if(flag[i]){
			ans+=c[i];
			f++;
			for(int j=1;j<=n;j++){
				e[++sum].u=n+i;
				e[sum].v=j;
				e[sum].w=a[i][j];
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		cnt++;
		ans+=e[i].w;
		if(cnt==n+f-1)break;
	}	
	cout<<ans;
	return 0;
}
