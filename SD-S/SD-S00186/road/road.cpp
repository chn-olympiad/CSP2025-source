#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<' '<<x<<'\n'
#define int long long
const int M=1e6+5;
const int N=1e5+5;
int n,m,k,fa[M],c[20],f[1005][1005];
struct node{
	int u,v,w;
}a[M*10];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void work1(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld",&u);
		scanf("%lld",&v);
		scanf("%lld",&w);
		a[i]={u,v,w};		
	} 
	sort(a+1,a+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=a[i].w;
			if(++cnt==n-1)break;
		}	
	}
	printf("%lld\n",ans);
}
int g[15][N];
void work2(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld",&u);
		scanf("%lld",&v);
		scanf("%lld",&w);
		if(u>v)swap(u,v);
		f[u][v]=w;		
	} 
	
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&g[i][j]);
		}
	}
	for(int e=1;e<=k;e++){		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=min(g[e][i]+g[e][j]+c[e],f[i][j]);
			}
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
//		debug(i);
		for(int j=i+1;j<=n;j++){
			a[++cnt]={i,j,f[i][j]};
			fa[cnt]=cnt;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int cntt=0,ans=0;
	for(int i=1;i<=cnt;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=a[i].w;
			if(++cntt==n-1)break;
		}	
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&k);
	if(k==0){
		work1();
		return 0;	
	}
	if(n<=1000){
		work2();
		return 0;
	}
	/*
	
	//freopen
	
	´ð°¸ÊÇ42
	
	*/ 
	return 0;
} 
