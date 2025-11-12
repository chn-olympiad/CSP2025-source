#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7,M=2e6+7;
int n,m,k,fa[N],c[13],a[13][N],cnt,tot,ans,vis[M],deg[13];
bool subA=true,flg,used[N];

int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}

struct edge{
	int f,t,v;
}d[M];

bool cmp(edge x,edge y){
	return x.v<y.v;
}

inline void dfs(int x){
	if(x>k){
		tot=0;
		int tal=0,t=0;
		for(int i=1;i<=k;++i)
			if(used[i]){
				tal+=c[i];
				++t;
			} 
//		for(int i=1;i<=k;++i)
//			cout<<used[i]<<" ";
//		cout<<"\n";
	//	sort(d+1,d+1+cnt,cmp);
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		for(int i=1;i<=cnt;++i){
			if(d[i].f>n&&!used[d[i].f-n])
			   	continue;
			int x=find(d[i].f),y=find(d[i].t);
			if(x!=y){
				fa[x]=y;
				++tot;
				tal+=d[i].v;
				if(tot==n+t-1){
					ans=min(ans,tal);
					return;
				}
			}
		}		
		return;
	}
	dfs(x+1);
	used[x]=1;
	dfs(x+1);
	used[x]=0;
}

int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
		d[i].f=read(),d[i].t=read(),d[i].v=read();
	cnt=m;
	for(int i=1;i<=n+k;++i)
		fa[i]=i;
	for(int i=1;i<=k;++i){
		flg=false;
		c[i]=read();
		if(c[i])
			subA=false;
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			d[++cnt]={n+i,j,a[i][j]};
			if(!a[i][j])
				flg=true;
		}
		subA=subA&&flg;
	}
	if(subA||!k){
		sort(d+1,d+1+cnt,cmp);
		for(int i=1;i<=cnt;++i){
			int x=find(d[i].f),y=find(d[i].t);
			if(x!=y){
				fa[x]=y;
				++tot;
				ans+=d[i].v;
				if(tot==n+k-1){
					printf("%lld",ans);
					return 0;
				}
			}
		}
	}else{
		sort(d+1,d+1+cnt,cmp);
		ans=LLONG_MAX;
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
