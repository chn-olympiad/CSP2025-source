#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
node a[1100000];
int fa[1100000];
int l[1100000];
int out[1100000],r[1100000];
bool cmp(node a,node b){
	return a.w<b.w;
}
int getfa(int x){
	if(x==fa[x])return x;
	else {
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
}
void merge(int u,int v){
	if(fa[u]!=u){
        fa[v]=u;
	}else fa[u]=v;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);

	int mu=0;
	int mv=0;
	int min1=1e9;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	int cnt=m;
	for(int j=1;j<=k;++j){
		int c;
		scanf("%d",&c);
		for(int i=1;i<=n;++i){
			int ww;
			scanf("%d",&ww);
			++cnt;
			a[cnt].u=n+j;
			a[cnt].v=i;
			a[cnt].w=ww;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		fa[i]=i;
	}
	int tmp=1;
	int flag=0;
	long long ans=0;
	memset(l,0,sizeof l);
	memset(out,0,sizeof out);
	memset(r,0,sizeof r);
	while(flag<n-1){
		int u=a[tmp].u;
		int v=a[tmp].v;
		if(getfa(u)==getfa(v)){
			tmp++;
			continue;
		}
		ans+=a[tmp].w;
		merge(u,v);
		flag++;
		out[u]++;out[v]++;
		if(u>n && l[u]==0){
			flag--;l[u]=1;
			if(out[u]==1)r[u]=a[tmp].w;
		}else if (v>n && l[v]==0){
			flag--;l[v]=1;
			if(out[v]==1)r[v]=a[tmp].w;
		}
		//printf("%d %d %d %d\n",u,v,a[tmp].w,flag);
		tmp++;
	}
	for(int i=n+1;i<=n+k;++i){
		if(out[i]==1){
			ans-=r[i];
			cout<<i<<endl;
		}
	}
	printf("%d\n",ans);
	return 0;
}

