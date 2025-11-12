#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,n1;
struct Node{
	int u,v,w;
};
Node q[1000010];
Node q2[10010];
Node q1[1000010];
int val[11];
int a[11][10010];
int fa[10010];
long long res=1e18;
long long ans;
int len=0;
int mxw;
int cmp(Node a,Node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);

}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u=q[i].u;
		int v=q[i].v;
		int w=q[i].w;
		u=find(u);
		v=find(v);
		if(u!=v){
			fa[u]=v;
			q2[++cnt]=q[i];
			mxw=max(mxw,q[i].w); 
		}
	}
	for(int i=0;i<(1<<k);i++){
		cnt=n-1;
		ans=0;
		len=0;
		n1=n;
		for(int j=1;j<=n-1;j++){
			q1[j]=q2[j];
		}
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				ans+=val[j];
				n1++;
				for(int l=1;l<=n;l++){
					if(a[j][l]>mxw) continue;
					q1[++cnt].u=n1;
					q1[cnt].v=l;
					q1[cnt].w=a[j][l];
				}
			}
		}
		for(int j=1;j<=n1;j++){
			fa[j]=j;
		}
		sort(q1+1,q1+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int u=q1[i].u;
			int v=q1[i].v;
			u=find(u);
			v=find(v);
			if(u!=v){
				ans+=q1[i].w;
				fa[u]=v;
				len++;
			}
		}
		res=min(res,ans);
	}
	printf("%lld",res);
	return 0;
}


